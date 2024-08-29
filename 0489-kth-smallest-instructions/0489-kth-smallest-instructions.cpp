#define ll long long
class Solution {
public:
    ll total, base_rank;
    ll combination(ll n, ll r)
    {
        ll ans = 1;
        for(ll i=1; i<=r; i++)
        {
            ans = ans * (n-i+1)/i;
        }
        return ans;
    }
    void solve(ll H, ll V, int &k, string &output)
    {
        if(!H && !V)
            return;
        if(!H){
            output.push_back('V');
            solve(H, V-1, k, output);
            return;
        }
        else if(!V){
            output.push_back('H');
            solve(H-1, V, k, output);
            return;
        }

        ll rank = total - combination(H+V-1, H) + 1;

        if(rank > k)
        {
            output.push_back('H');
            total = base_rank + combination(H+V-1, H-1);
            solve(H-1, V, k, output);
        }
        else if(rank <=k)
        {
            output.push_back('V');
            base_rank = rank - 1;
            solve(H, V-1, k, output);
        }
    }
    string kthSmallestPath(vector<int>& d, int k) {
        // cout << combination(5, 3) << endl;
        ll H = d[1];
        ll V = d[0];
        total = combination(H+V, H);
        base_rank = 0;

        string ans = "";
        solve(H, V, k, ans);

        return ans;
    }
};