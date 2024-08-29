class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int ind, bool isSwapped, vector<vector<int> > &dp){
        if(ind == nums1.size())
            return 0;

        if(dp[ind][isSwapped] != -1)
            return dp[ind][isSwapped];

        int ans = INT_MAX;
        // cout << ind
        int prev1 = nums1[ind-1];
        int prev2 = nums2[ind-1];

        if(isSwapped)
            swap(prev1, prev2);

        if(nums1[ind] > prev1 && nums2[ind] > prev2)
            ans = min(ans, solve(nums1, nums2, ind+1, false, dp));
        if(nums1[ind] > prev2 && nums2[ind] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, ind+1, true, dp));

        return dp[ind][isSwapped] = ans;

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int> > dp(nums1.size(), vector<int>(2, -1));

        return solve(nums1, nums2, 1, false, dp);
    }
};