class Solution {
public:
    static bool cmp(string &a, string &b)
    {
        return a.size() < b.size();
    }
    bool isValid(string a, string b){
        if(a.size()+1 != b.size())
            return false;
        int i=0, j=0, cnt=0;
        while(j<b.size())
        {
            if(a[i] == b[j])
                i++, j++;
            else
                j++, cnt++;
            if(cnt>1)
                return false;
        }
        return cnt <= 1 ?  true : false;
    }
    // int solve(vector<string> &words, int ind, int prev, vector<vector<int> > &dp){
    //     if(ind >=words.size())
    //         return 0;

    //     if(dp[ind][prev+1] != -1)
    //         return dp[ind][prev+1];
    //     int notTake = solve(words, ind+1, prev, dp);
    //     int take = 0;
    //     if(prev == -1 || isValid(words[prev], words[ind]))
    //         take = 1 + solve(words, ind+1, ind, dp);

    //     return dp[ind][prev+1] = max(notTake, take);
    // }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        int n = words.size();

        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        // return solve(words, 0, -1, dp);

        for(int ind = n-1; ind>=0; ind--){
            for(int prev = ind-1; prev>=-1; prev--){
                int notTake = dp[ind+1][prev+1];
                int take = 0;
                if(prev == -1 || isValid(words[prev], words[ind]))
                    take = 1 + dp[ind+1][ind+1];

                dp[ind][prev+1] = max(notTake, take);
            }
        }

        return dp[0][0];


    }
};