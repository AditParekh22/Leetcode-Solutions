static bool compare(int A, int B){
    return (to_string(A) + to_string(B))>(to_string(B) + to_string(A));
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string ans = "";
        
        for(auto it : nums)
            ans += to_string(it);

        if(ans[0]=='0') return "0";
        return ans;
    }
};