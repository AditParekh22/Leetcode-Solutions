#define f first
#define s second
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int> > arr;
        for(int i=0; i<n; i++)
            arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end());

        int left = 0, right = n-1;
        while(left<right){
            if(arr[left].f + arr[right].f == target)
                return{arr[left].s, arr[right].s};
            else if(arr[left].f + arr[right].f > target)
                right--;
            else
                left++;
        }
        return {}; // No solution found
    }
};