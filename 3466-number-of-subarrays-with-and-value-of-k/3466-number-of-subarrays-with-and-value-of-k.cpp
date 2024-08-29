#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        map<int, int> prev;
        for(int i=0; i<n; i++)
        {
            map<int, int> curr;
            for(auto it : prev)
                curr[it.first & nums[i]] += it.second;
            curr[nums[i]]++;

            for(auto it: curr){
                if(it.first == k)
                    ans +=it.second;
            }
            prev=curr;
        }
        return ans;
    }
};