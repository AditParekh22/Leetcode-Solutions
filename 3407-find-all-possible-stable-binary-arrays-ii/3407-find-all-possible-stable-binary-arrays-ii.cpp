class Solution {
public:
    int mod = 1e9 +7;
    int numberOfStableArrays(int z, int o, int limit) {
        long long res = 0;
        vector<vector<vector<int> > >dp(3, vector<vector<int> >(z+1, vector<int>(o+1, 0)));
        // return solve(l, z, o, -1, dp);

        for(int zero=1; zero<=min(z, limit); zero++)
            dp[0][zero][0] = 1;
        for(int one=1; one<=min(o, limit); one++)
            dp[1][0][one] = 1;

        for(int zero = 1; zero<=z; zero++)
        {
            for(int one = 1; one<=o; one++)
            {
                dp[0][zero][one]  = (dp[0][zero-1][one] + dp[1][zero-1][one])%mod;
                dp[1][zero][one]  = (dp[0][zero][one-1] + dp[1][zero][one-1])%mod;

                if(zero>limit)
                    dp[0][zero][one]  = (dp[0][zero][one] - dp[1][zero-limit-1][one] + mod)%mod;
                if(one>limit)
                    dp[1][zero][one]  = (dp[1][zero][one] - dp[0][zero][one-limit-1] + mod)%mod;
                
            }
        }
        return (dp[0][z][o] + dp[1][z][o])%mod;
    }
};