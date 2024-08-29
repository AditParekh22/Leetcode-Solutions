class Solution {
public:
    int intial = (1<<20) -1;
    vector<vector<unordered_map<int, int>>> dp;
    int solve(vector<int>&nums, vector<int> &values, int i, int j, int and_val)
    {
        if(i>=nums.size() && j>=values.size())
            return 0;
        if(i>=nums.size())
            return 1e9;
        if(j==values.size()-1)
        {
            while(i<nums.size()){
                and_val &= nums[i];
                i++;
            }
            if(and_val != values[j])
                return 1e9;
            return nums[i-1];
        }
        if(dp[i][j].count(and_val))
            return dp[i][j][and_val];

        and_val = and_val & nums[i];
        int ans = 0;
        if(and_val == values[j])
        {
            ans = min(solve(nums, values, i+1, j+1, intial) + nums[i], 
                solve(nums, values, i+1, j, and_val));
        }
        else
            ans = solve(nums, values, i+1, j, and_val);

        return dp[i][j][and_val] = ans;
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        int m = andValues.size();

        dp.resize(n, vector<unordered_map<int, int> >(10));
        int ans = solve(nums, andValues, 0, 0, intial);
        return ans>=1e9 ? -1 : ans;
    }
};