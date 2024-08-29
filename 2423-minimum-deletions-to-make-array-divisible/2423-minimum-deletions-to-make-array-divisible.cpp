class Solution {
public:
    long long GCD(vector<int>& d){
        if(d.size() == 1)
            return d[0];
        long long g = __gcd(d[0], d[1]);
        for(int i=2; i<d.size(); i++){
            g = __gcd(g, (long long)d[i]);
        }
        return g;
    }
    int minOperations(vector<int>& nums, vector<int>& d) {
        long long g = GCD(d);
        sort(nums.begin(), nums.end());
        // for(auto it : nums)
        //     cout << it << " ";
        // cout << endl;
        for(int i=0; i<nums.size(); i++)
        {
            if(g%nums[i] == 0)
                return i;
        }
        return -1;
    }
};