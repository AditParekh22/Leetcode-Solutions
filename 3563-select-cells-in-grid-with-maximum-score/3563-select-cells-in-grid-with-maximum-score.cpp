class Solution {
public:
    unordered_map<int, vector<int> >mp;
    int dp[101][1024];
    int solve(int nums, int mask){

        if(nums>100)
            return 0;
        if(dp[nums][mask] != -1)
            return dp[nums][mask];
        int ans = solve(nums+1, mask);
        // cout << nums << " "<< mp[nums].size() << endl;
        for(auto it : mp[nums]){
            // cout << "\t"<<it << endl;
            if(((1<<it) & mask) == 0){
                // cout << nums << endl;
                ans = max(ans, nums + solve(nums+1, mask | (1<<it)));
            }
        }

        return dp[nums][mask] = ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[grid[i][j]].push_back(i);
            }
        }
        memset(dp, -1, sizeof(dp));

        return solve(0, 0);
    }
};