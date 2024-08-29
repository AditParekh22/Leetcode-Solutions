class Solution {
public:
    int solveRec(int index, int endIndex, vector<int>& slices, int n, vector<vector<int> > &dp)
    {
        // Base case
        // You have eaten all the pizza slice that can be eaten by a single person
        if(n == 0 || index >endIndex)   
            return 0;

        if(dp[index][n] != -1)
            return dp[index][n];

        int include = slices[index] + solveRec(index+2, endIndex, slices, n-1, dp);
        int exclude = 0 + solveRec(index+1, endIndex, slices, n, dp);

        return dp[index][n] = max(include, exclude);
        
    }

    int solveTab(vector<int>& slices)
    {
        int n = slices.size();
        vector<vector<int>> dp1(n+2, vector<int>(n, 0));
        vector<vector<int>> dp2(n+2, vector<int>(n, 0));
        // n+2 as whe doing this dp1[i+2][j-1] i will show index out of bounds error;
        // Case 1
        for(int i=n-2; i>=0; i--)
        {
            for(int j=1; j<=n/3; j++)
            {
                int include = slices[i] +dp1[i+2][j-1];
                int exclude = 0 + dp1[i+1][j];

                dp1[i][j] = max(include, exclude);
            }
        }
        int case1 = dp1[0][n/3];

        // Case 2
        for(int i=n-1; i>=1; i--)
        {
            for(int j=1; j<=n/3; j++)
            {
                int include = slices[i] +dp2[i+2][j-1];
                int exclude = 0 + dp2[i+1][j];

                dp2[i][j] = max(include, exclude);
            }
        }
        int case2 = dp2[1][n/3];

        return max(case1, case2);
    }

    int solveOpt(vector<int>& slices)
    {
        int n = slices.size();
        // n+2 as whe doing this dp1[i+2][j-1] i will show index out of bounds error;
        
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        vector<int> next(n, 0);

        
        // Case 1
        for(int i=n-2; i>=0; i--)
        {
            for(int j=1; j<=n/3; j++)
            {
                int include = slices[i] + next[j-1];
                int exclude = 0 + curr[j];

                prev[j] = max(include, exclude);
            }
            next = curr;
            curr = prev;
        }
        int case1 = curr[n/3];

        vector<int> prev1(n, 0);
        vector<int> curr1(n, 0);
        vector<int> next1(n, 0);

        // Case 2
        for(int i=n-1; i>=1; i--)
        {
            for(int j=1; j<=n/3; j++)
            {
                int include = slices[i] +next1[j-1];
                int exclude = 0 + curr1[j];

                prev1[j] = max(include, exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case2 = curr1[n/3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) 
    {
        int k = slices.size();
        // Here given that there are 3n pizza slices and there are 3 people
        // Pizza slice eaten by one person is k/3

        // Here if we include 1st element last will not be include
        // If we include last 1st will not be included
        
        // vector<vector<int> > dp1(k, vector<int>(k, -1));
        // int case1 = solveRec(0, k-2,slices, k/3, dp1);

        // vector<vector<int> > dp2(k, vector<int>(k, -1));
        // int case2 = solveRec(1, k-1,slices, k/3, dp2);

        // return max(case1, case2);

        return solveOpt(slices);


        
    }
};