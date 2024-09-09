class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> prev;

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            set<int> curr;

            for(auto it : prev){
                // cout << it << " ";
                int val = it | nums[i];
                curr.insert(val);
            }
            // cout << endl;

            curr.insert(nums[i]);

            for(auto it : curr){
                // cout << it << " - ";
                ans=min(ans, abs(it - k));
            }
            // cout << endl;

            prev = curr;
        }

        return ans;
    }
};