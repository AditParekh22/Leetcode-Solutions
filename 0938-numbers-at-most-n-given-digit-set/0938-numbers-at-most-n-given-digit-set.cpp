class Solution {
public:
    int solve(vector<int> &d, string s, int ind, int flag, vector<vector<int> > &dp){
        if(ind >= s.size())
            return 1;

        if(dp[ind][flag] != -1)
            return dp[ind][flag];

        int limit = (flag == 1 ? s[ind]-'0' : d[d.size()-1]);
        int ans = 0;
        for(int i=0; i<d.size(); i++){
            if(d[i]>limit)
                break;
            ans += solve(d, s, ind+1, flag & (d[i] == limit), dp); 
        }

        return dp[ind][flag] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> d;
        for(auto it : digits)
            d.push_back(stoi(it));

        string s = to_string(n);
        int len = s.size();

        vector<vector<int> > dp(len, vector<int>(2, -1));

        int ans = solve(d, s, 0, 1, dp);

        int pro = d.size();
        for(int i = 1; i<len; i++){
            ans += pro;
            pro = pro*d.size();
        }

        return ans;

        
    }
};