#define ll long long
class Solution {
public:
    bool inRange(int val, int mini, int maxi){
        if(val>=mini && val<=maxi)  
            return true;
        return false;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll n = nums.size();
        int ind = -1, l = -1, r=-1;
        ll ans = 0;
        for(int i=0; i<n; i++){
            if(!inRange(nums[i], minK, maxK))
                ind = i;

            if (nums[i] == minK) 
                l = i;

            if (nums[i] == maxK) 
                r = i;

            ans += max(0, min(l,  r)-ind);
        }

        return ans;
    }
};
