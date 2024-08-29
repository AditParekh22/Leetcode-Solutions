class Solution {
public:

    int solveRec(vector<int> &sat, int index, int time, vector<vector<int> > &dp)
    {
        if(index == sat.size())
        {
            return 0;
        }

        if(dp[index][time] != -1)
            return dp[index][time];

        // Include
        int ans1 = solveRec(sat, index+1, time+1, dp) + sat[index] * time;

        // Exclude
        int ans2 = solveRec(sat, index+1, time, dp);
        
        dp[index][time] =  max(ans1, ans2);
        return dp[index][time];
    }

    int solveTab(vector<int> &sat)
    {
        int n =  sat.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int index=n-1; index>=0; index--)
        {
            for(int time = index; time>=0; time--)
            {
                // Include
                int ans1 = dp[index+1][time+1] + sat[index] * (time+1);

                // Exclude
                int ans2 = dp[index+1][time];
                
                dp[index][time] =  max(ans1, ans2);
            }
            
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {

        // int n = satisfaction.size();
        // vector<vector<int> > dp(n, vector<int>(n+1, -1));
        sort(satisfaction.begin(), satisfaction.end());

        return solveTab(satisfaction);
        // return solveRec(satisfaction, 0, 1, dp);
    }
};