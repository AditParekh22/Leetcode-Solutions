#define ll long long
class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size() ==1)
            return to_string(stol(n) - 1);
        
        ll d = n.size();
        vector<ll> c;
        c.push_back(pow(10, d)+1);
        c.push_back(pow(10, d-1)-1);

        ll mid = (d+1)/2;

        ll prefix = stol(n.substr(0, mid));
        vector<ll> v = {prefix, prefix+1, prefix-1};
        for(auto it: v)
        {
            string postfix = to_string(it);
            if(d&1)
                postfix.pop_back();
            reverse(postfix.begin(), postfix.end());
            string temp = to_string(it) + postfix;
            c.push_back(stol(temp));
            // cout<< postfix << endl;
        }
        ll mini = INT_MAX;
        ll num = stol(n);
        ll ans = 0;

        for(auto it : c)
        {
            if(it != num && abs(it-num)<mini)
            {
                mini = abs(it-num);
                ans = it;
            }
            else if(abs(it-num) == mini)
                ans = min(ans, (ll)it);
        }

        return to_string(ans);





        
        
    }
};