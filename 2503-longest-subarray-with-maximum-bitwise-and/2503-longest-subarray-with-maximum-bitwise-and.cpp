class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> prev;
        int maxi = INT_MIN, ans = 0;

        for(int i=0; i<n; i++){
            // cout << "i : " << i << endl;
            unordered_map<int, int> curr;
            for(auto it : prev)
                curr[it.first & nums[i]] = it.second+1;
            
            if(curr.find(nums[i]) == curr.end())
                curr[nums[i]] = 1;

            for(auto it : curr){
                // cout << it.first << " " << it.second << endl;
                if(it.first > maxi){
                    // cout << it.first << " x " << it.second << endl;
                    maxi = it.first;
                    ans = it.second;
                }
                else if(it.first == maxi)
                    ans = max(ans, it.second);
            }

            prev = curr;
        }   
        return ans;
    }
};