class Solution {
public:
    int dp[102][102];
    int solve(vector<vector<int> > &c, int ind, int prev){
        if(ind >= c.size())
            return 0;

        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];

        int take = 0;
        if(prev == -1 || (c[prev][0]>=c[ind][0] && c[prev][1]>=c[ind][1] && c[prev][2]>=c[ind][2])){
            take = c[ind][2] + solve(c, ind+1, ind);
        }
        int notTake = solve(c, ind+1, prev);

        return dp[ind][prev+1] = max(take, notTake);
    }
    int maxHeight(vector<vector<int>>& c) {
        int n = c.size();
        for(int i=0; i<n; i++)
            sort(c[i].begin(), c[i].end());
        sort(c.begin(), c.end(), greater<vector<int>>());

        memset(dp, -1, sizeof(dp));

        return solve(c, 0, -1);

    }
};