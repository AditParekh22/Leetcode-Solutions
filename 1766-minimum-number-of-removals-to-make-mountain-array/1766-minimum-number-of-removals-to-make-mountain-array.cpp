class Solution {
public:
    void LIS(vector<int> nums, vector<int> &dp){
        int n = nums.size();

        for(int ind = 0; ind<n; ind++){
            for(int prev = 0; prev<ind; prev++){
                if(nums[prev] < nums[ind])
                    dp[ind] = max(dp[ind], dp[prev]+1);
            }
        }

        
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans1(n, 1), ans2(n, 1);
        LIS(nums, ans1);
        for(auto it : ans1)
            cout << it << " ";
        cout << endl;
        reverse(nums.begin(), nums.end());

        LIS(nums, ans2);
        int  maxi = INT_MIN;
        reverse(ans2.begin(), ans2.end());

        for(auto it : ans2)
            cout << it << " ";
        cout << endl;
        for(int i=1; i<n-1; i++){
            if(ans1[i] > 1 && ans2[i]>1)
                maxi = max(maxi, ans1[i] + ans2[i] - 1);
        }

        return n - maxi;


    }
};