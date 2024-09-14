class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        cout << n << endl;
        int maxi = *max_element(nums.begin(), nums.end());
        int ans= 0, length = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == maxi)
                ans = max(ans, ++length);
            else
                length = 0;
        }
        return ans;


    }
};