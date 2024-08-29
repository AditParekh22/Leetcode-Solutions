#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll sum = 0, j = 0, ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            while(sum*(i-j+1)>=k)
            {
                sum -=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};