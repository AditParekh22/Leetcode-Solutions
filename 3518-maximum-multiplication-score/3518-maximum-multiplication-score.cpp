class Solution {
public:
    long long dp[100001][5];
    long long solve(vector<int> &a, vector<int> &b, int ind, int k){
        if(k == a.size())
            return 0;
        if(ind>=b.size() && k<a.size())
            return -1e9;
        if(ind>=b.size())
            return 0;
        if(dp[ind][k] != -1)
            return dp[ind][k];

        long long take = (long long)a[k] * (long long)b[ind] + solve(a, b, ind+1, k+1);
        long long notake = solve(a, b, ind+1, k);

        return dp[ind][k] = max(take, notake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        memset(dp, -1, sizeof(dp));
        return solve(a, b, 0, 0);
    }
};