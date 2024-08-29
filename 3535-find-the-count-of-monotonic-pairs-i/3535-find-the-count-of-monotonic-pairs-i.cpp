#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    int dp[2001][52][52];
    int solve(vector<int> &nums, int ind, int arr1, int arr2){
        if(ind == nums.size())
            return 1;
        if(dp[ind][arr1][arr2] != -1)
            return dp[ind][arr1][arr2];
        int ans = 0;
        for(int i=0; i<=nums[ind]/2; i++){
            int take = i;
            int rem = nums[ind] - i;
            // cout << take << " " << rem << endl;

            if(take>=arr1 && rem<=arr2){
                ans = (ans%mod + solve(nums, ind+1, take, rem)%mod)%mod;
            }
            if(take != rem && rem>=arr1 && take<=arr2){
                ans = (ans%mod + solve(nums, ind+1, rem, take)%mod)%mod; 
            }           
        }
        return dp[ind][arr1][arr2] = ans%mod;

    }
    int countOfPairs(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 51)%mod;
        
    }
};