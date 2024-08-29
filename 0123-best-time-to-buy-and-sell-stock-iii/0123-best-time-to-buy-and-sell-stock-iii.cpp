class Solution {
public:
    int dp[100001][5];
    int solve(vector<int> &prices, int ind, int isBuy)
    {
        if(isBuy>4 || ind>=prices.size())
            return 0;
        if(dp[ind][isBuy] != -1)
            return dp[ind][isBuy];
        if(isBuy&1)
        {
            return dp[ind][isBuy] = max(solve(prices, ind+1, isBuy+1) - prices[ind], 
                        solve(prices, ind+1, isBuy));
        }
        else
        {
            return dp[ind][isBuy] = max(solve(prices, ind+1, isBuy+1) + prices[ind], 
                        solve(prices, ind+1, isBuy));
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 1);
    }
};