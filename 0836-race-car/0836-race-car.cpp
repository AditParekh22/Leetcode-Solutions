class Solution {
public:
    int solve(int target, vector<int> &dp){
        if(target == 0)
            return 0;
        if(dp[target] != -1)
            return dp[target];


        int m = log2(target) + 1;
        // Case A
        if(target == (1<<m)-1)
            return m;

        // Case B1
        int ans = m + 1 + solve((1<<m) - 1 - target, dp);

        // Case B2
        for(int i=0; i<= m - 2; i++){
            ans = min(ans, m + i + 1 + solve(target-(1<<(m-1)) + (1<<i), dp));
        }
        return dp[target] = ans;
    }
    int racecar(int target) {
        vector<int> dp(target+1, -1);
        return solve(target, dp);
    }
};