class Solution {
public:
    vector<vector<vector<int> > >dp;
    int solve(string &s, int ind, int cnt, int flag){
        if(ind >= s.size())
            return cnt;
        if(dp[ind][cnt][flag] != -1)
            return dp[ind][cnt][flag];

        int limit = (flag == 1 ? s[ind]-'0' : 9);
        int ans = 0;

        for(int i=0; i<=limit; i++){
            int updCnt = cnt + (i == 1 ? 1 : 0);
            ans += solve(s, ind+1, updCnt, flag & (i == (s[ind]-'0'))); 
        }
        return dp[ind][cnt][flag] = ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        dp.resize(12, vector<vector<int> > (12, vector<int>(2, -1)));
        return solve(s, 0, 0, 1);
    }
};