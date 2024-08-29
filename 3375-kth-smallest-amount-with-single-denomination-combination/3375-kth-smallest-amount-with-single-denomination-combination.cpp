#define ll long long int
class Solution {
public:
    ll solve(vector<int> &coins, ll mid)
    {
        ll n = coins.size();
        ll allOnes = (1<<n)-1;

        ll cnt = 0;
        for(int mask=1; mask <= allOnes; mask++)
        {
            ll setBitsLcm = 1;
            for(int j=0; j<n; j++)
            {
                if(mask & (1<<j))
                    setBitsLcm = lcm(setBitsLcm, coins[j]);
            }
            if(__builtin_popcount(mask) & 1)
                cnt += (mid / setBitsLcm);
            else
                cnt -= (mid / setBitsLcm);
        }
        return cnt;

    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll s = 0, e = 1e11, ans=0;
        

        while(s<=e)
        {
            ll  mid = (s + e)/2;
            ll cnt = solve(coins, mid);
            if(cnt<k)
            {
                s = mid+1;
                
            }
            else{
                ans = mid;
                e = mid-1;
            }
                
            // mid = s + (e-s)/2;
        }
        return ans;
    }
};