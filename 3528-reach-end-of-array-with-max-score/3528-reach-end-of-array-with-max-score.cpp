class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        long long int ans=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[prev]){
                ans += (long long)((long long int)nums[prev] * (i-prev));
                prev = i;
            }
        }
        ans += (long long)((long long int)nums[prev] * (n-1-prev));

        return ans;
    }
};