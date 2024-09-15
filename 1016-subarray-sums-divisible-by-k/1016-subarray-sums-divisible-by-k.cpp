class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(k, 0);
        sum[0]++;
        int ans = 0, pref = 0;

        for(int i=0; i<n; i++){
            pref = (pref + (nums[i]%k) + k)%k;
            cout << i << " " << pref << endl;
            ans += sum[pref]++;
        }
        return ans;
    }
};