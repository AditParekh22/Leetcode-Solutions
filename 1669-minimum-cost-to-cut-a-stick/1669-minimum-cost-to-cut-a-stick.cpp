class Solution {
public:
    int solve(vector<int> &cuts, int i, int j, vector<vector<int> >&dp)
    {
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        // cout << i<< " " << j << endl;
        for(int k=i; k<=j; k++)
        {
            int cost = (cuts[j+1] - cuts[i-1]) 
                    + solve(cuts, i, k-1, dp) 
                    + solve(cuts, k+1, j, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int> > dp(len+1, vector<int>(len+2, -1));
        return solve(cuts, 1, len, dp);
        // return -1;
    }
};