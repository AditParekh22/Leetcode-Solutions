#define ll long long
class Solution {
public:
    ll mod  = 1e9+7;
    ll solve(ll steps, ll ind, ll arrLen, vector<vector<ll> > &dp)
    {
        // cout << ind << " " << steps<< endl;
        if(ind == 0 && steps == 0)
            return 1;
        if(steps<=0 || ind >=arrLen || ind<0)
            return 0;

        if(dp[ind][steps] != -1)
            return dp[ind][steps];
        ll right=0, left = 0;
        if(ind+1<arrLen)
            right = solve(steps-1, ind+1, arrLen, dp)%mod;
        if(ind-1>=0)
            left  = solve(steps-1, ind-1, arrLen, dp)%mod;
        ll stay = solve(steps-1, ind, arrLen, dp)%mod;

        return dp[ind][steps] = (right+left+stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        int len = min((steps+1)/2+1, arrLen);
        vector<vector<ll> > dp(len, vector<ll>(steps+1, -1));
        return solve(steps, 0, len, dp)%mod;
    }
};