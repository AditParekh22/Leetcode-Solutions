class Solution {
public:
    int mod = 1000000007;
    // int solve(int n, int k)
    // {
    //     if(k == 0)
    //         return 1;
    //     if(n == 0)
    //         return 0;
    //     if(dp[n][k] != -1)
    //         return dp[n][k];
    //     int ans = 0;
    //     for(int i=0;i<=min(n-1, k); i++)
    //     {
    //         ans = (ans + solve(n-1, k-i))%mod;
    //     }
    //     return dp[n][k] = ans;
    // }
    int kInversePairs(int n_count, int target) {
        // return solve(n, k);
        int dp[n_count+1][target+1];
        memset(dp, 0,sizeof(dp));

        for(int n=0;n<=n_count; n++)
            dp[n][0] = 1;

        for(int n=1; n<=n_count; n++)
        {
            for(int k=1; k<=target; k++)
            {
                int ans = 0;
                dp[n][k] = (dp[n-1][k] + dp[n][k-1])%mod;
                if(k>=n)
                    dp[n][k] = (dp[n][k] - dp[n-1][k-n] + mod)%mod;
            }
        }
        // for(int i=0;i<=n_count; i++)
        // {
        //     for(int j=0;j<=target; j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        return dp[n_count][target];
    }
};