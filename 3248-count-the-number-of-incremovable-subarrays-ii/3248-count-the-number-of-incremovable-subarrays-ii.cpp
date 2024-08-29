#define ll long long
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        ll n = nums.size();
        ll leftInd = 0, rightInd = nums.size()-1;

        for(int i=0; i<n-1; i++){
            if(nums[i] < nums[i+1]) leftInd++;
            else break;
        }

        if(leftInd == n-1)
            return (n*(n+1))/2;

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]) rightInd--;
            else break;
        }
        
        cout << leftInd << endl;
        ll ans = n - rightInd + 1;
        for(int i=0; i<=leftInd; i++)
        {
            ll ub = upper_bound(nums.begin()+rightInd, nums.end(), nums[i]) - nums.begin();
            ans += n-ub+1;
        }
        return ans;

    }
};