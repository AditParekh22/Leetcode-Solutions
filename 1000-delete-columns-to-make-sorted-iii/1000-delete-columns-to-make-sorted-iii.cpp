class Solution {
public:
    bool isValid(vector<string>& strs,int ind,int last)
    {
        // if(last==0)
        //     return true;
        int n=strs.size();
        // ind-=1;
        // last-=1;
        for(int i=0;i<n;i++)
        {
            if(strs[i][ind] < strs[i][last])
                return false;
        }
        return true;
    }
    int solve(vector<string> &str, int ind, int prev, vector<vector<int> > &dp)
    {
        if(ind >= str[0].size())
            return 0;
        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1];

        // Deleting
        int ans = INT_MAX;
        ans = min(ans, 1 + solve(str, ind+1,prev, dp));
        
        // Keeping the current
        if(prev ==-1 || isValid(str, ind, prev))
        {
            ans = min(ans, solve(str, ind+1, ind, dp));
        }

        return dp[ind][prev+1] = ans;
    }
    int minDeletionSize(vector<string>& str) {
        int n = str.size();
        int m = str[0].size();
        vector<vector<int> >dp(m+1, vector<int>(m+1, -1));
        return solve(str, 0, -1, dp);
    }
};