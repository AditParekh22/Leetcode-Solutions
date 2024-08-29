class Solution {
public:
    int dp[10][2][1<<10];
    int solve(string s, int ind, int flag, int mask){
        if(ind == s.size())
            return mask == 0 ? 0 : 1;
        if(dp[ind][flag][mask] != -1)
            return dp[ind][flag][mask];
        int limit = (flag == 1 ? s[ind]- '0' : 9);
        int ans = 0;

        for(int i=0; i<=limit; i++){
            if(mask == 0 && i == 0) {
                ans += solve(s, ind + 1, (flag & (limit == i)), mask);
                continue;
            }
            if(!(mask & (1<<i)))
                ans += solve(s, ind+1, flag & (limit==i), mask | (1<<i));
        }

        return dp[ind][flag][mask] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string r = to_string(n);
        memset(dp, -1, sizeof(dp));

        return n-solve(r, 0, 1, 0);

    }
};