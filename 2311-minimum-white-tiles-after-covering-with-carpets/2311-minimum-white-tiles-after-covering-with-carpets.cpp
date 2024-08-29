class Solution {
public:
    int solve(int i, int k, int kl, string &s, vector<vector<int>> & dp){
        if(i < 0)return 0;
        if(k == 0){
            int ones = 0;
            for(int x=0; x<=i; x++){
                ones += (s[x]=='1');
            }
            return ones;
        }
        if(dp[i][k] != -1)return dp[i][k];

        int take = solve(i-1, k, kl, s, dp) + (s[i] == '1');
        int notake = solve(i-kl, k-1, kl, s, dp);

        return dp[i][k] = min(take, notake);
    }

    int minimumWhiteTiles(string s, int k, int kl) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(k+1, -1));
        return solve(n-1, k, kl, s, dp);
    }
};