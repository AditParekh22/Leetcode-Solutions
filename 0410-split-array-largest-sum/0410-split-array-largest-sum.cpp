class Solution {
public:
    bool isPossible(vector<int> &nums, int k, int limit){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] <= limit)
                sum += nums[i];
            else{
                if(k == 1 || nums[i]>limit)
                    return false;
                sum = nums[i];
                k--;
            }
        }
        if(sum>limit)
            return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int s = 0, e = sum;
        int mid = s + (e-s)/2;
        int ans = -1;

        while(s<=e){
            cout << mid << endl;
            if(isPossible(nums, k, mid))
            {
                ans = mid;
                e=mid-1;
            }
            else
                s = mid+1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
};