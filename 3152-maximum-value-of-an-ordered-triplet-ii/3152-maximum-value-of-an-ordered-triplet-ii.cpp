#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n);
        
        pref[0] = 0, suff[n-1] = 0;
        for(int i=1; i<n; i++){
            pref[i] = max(nums[i-1], pref[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            suff[i] = max(nums[i+1], suff[i+1]);
        }

        for(auto it : pref)
            cout << it << " ";
        cout << endl;

        for(auto it : suff)
            cout << it << " ";
        cout << endl;

        long long ans = INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(ans, ((ll)(pref[i] - nums[i]) * (ll)suff[i]));
        }

        return ans;
    }
};