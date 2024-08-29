class Solution {
public:
    void kmp(vector<int> &lps, string word)
    {
        int n = word.size();
        lps.resize(n);
        lps[0] = 0;

        for(int i=1; i<n; i++)
        {
            int prev_ind = lps[i-1];
            while(prev_ind>0 && word[prev_ind] != word[i])
                prev_ind = lps[prev_ind-1];
            lps[i] = prev_ind + (word[i] == word[prev_ind] ? 1 : 0);
        }
    }
    int minimumTimeToInitialState(string word, int k) {
        vector<int> lps;
        int n = word.size();

        kmp(lps, word);
        int maxLps = lps[n-1];

        // for(int i=0;i<lps.size(); i++)
        //     cout << lps[i] << " ";
        // cout << endl;

        while(maxLps>0 && (n-maxLps)%k !=0)
        {
            maxLps = lps[maxLps-1];
        }

        return (n-maxLps)%k == 0 ? (n-maxLps)/k : (n+k-1)/k;
    }
};