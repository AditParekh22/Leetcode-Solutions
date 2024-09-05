class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n-1];
        long long cnt = 0;

        for(int i=n-2; i>=0; i--){
            if(nums[i] > prev){
                int temp = nums[i]/prev;
                if(nums[i]%prev)
                    temp++;
                prev = nums[i]/temp;
                cnt += temp-1;
            }
            else
                prev = nums[i];
        }
        return cnt;
    }
};