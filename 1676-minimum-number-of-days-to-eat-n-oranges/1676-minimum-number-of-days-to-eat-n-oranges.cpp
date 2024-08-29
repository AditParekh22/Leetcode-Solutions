class Solution {
public:
    int recurdp(int n, unordered_map<int,int>&dp)
    {
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp.find(n)!= dp.end()) return dp[n];
        int x = n%2 + recurdp(n/2,dp);
        int y = n%3 + recurdp(n/3,dp);

        return dp[n] = 1+min(x,y);
    }
    int minDays(int n) {
        // vector<int>dp(n+1,-1);
        // return memo(n,dp);
        unordered_map<int,int>dp;
        return recurdp(n,dp);
    }
};