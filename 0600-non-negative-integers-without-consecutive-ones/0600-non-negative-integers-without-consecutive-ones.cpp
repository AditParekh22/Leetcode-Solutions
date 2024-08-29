class Solution {
public:
    int dp[32][3][3];
    int solve(string &s, int ind, int flag, int prev){
        if(ind == s.size())
            return 1;
        if(dp[ind][flag][prev] != -1)
            return dp[ind][flag][prev];
        int limit = (flag == 1 ? s[ind]-'0' : 1);
        int ans = 0;

        for(int i=0; i<=limit; i++){
            if(i == 1 && prev == 1)
                continue;
            ans += solve(s, ind+1, flag & (i == (s[ind]-'0')), i);
        }

        return dp[ind][flag][prev] = ans;
    }
    int findIntegers(int n) {
        string r="";
        for(int i=31; i>=0; i--){
            if(n & (1<<i))
                r.push_back('1');
            else
                r.push_back('0');
        }
        cout << r << endl;
        memset(dp, -1, sizeof(dp));

        return solve(r, 0, 1, 0);
        
    }
};