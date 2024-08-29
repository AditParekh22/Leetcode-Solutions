class Solution {
public:
    void kmp(vector<int>&lps, vector<int> &nums2)
    {
        int n = nums2.size();

        for(int i=1;i<n;i++)
        {
            int prev_ind = lps[i-1];
            while(prev_ind>0 && nums2[i] != nums2[prev_ind])
                prev_ind = lps[prev_ind-1];

            lps[i] = prev_ind + (nums2[i] == nums2[prev_ind] ? 1: 0);
        }

    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();

        vector<int> nums2 = pattern;
        nums2.push_back(-3);

        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1] > nums[i])
                nums2.push_back(1);
            else if(nums[i+1] == nums[i])
                nums2.push_back(0);
            else
                nums2.push_back(-1);
        }
        vector<int> lps(nums2.size());
        kmp(lps, nums2);
        int ans = 0;
        for(auto it: lps)   
        {
            if(it == pattern.size())
                ans++;
        }

        return ans;
    }
};