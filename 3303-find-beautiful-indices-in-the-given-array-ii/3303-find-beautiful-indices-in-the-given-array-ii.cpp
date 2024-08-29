class Solution {
public:
    void kmp(string s, vector<int> &lps)
    {
        lps.resize(s.size());
        lps[0] = 0;

        for(int i=1; i<s.size(); i++)
        {
            int prev_ind = lps[i-1];
            while(prev_ind>0 && s[i] != s[prev_ind])
            {
                prev_ind = lps[prev_ind-1];
            }

            lps[i] = prev_ind + (s[i] == s[prev_ind] ? 1 : 0); 

        }
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string sa = a + "#" + s;
        string sb = b + "#" + s;

        vector<int> lps;

        vector<int> va, vb;

        kmp(sa, lps);

        for(int i=a.size(); i<lps.size(); i++)
        {
            if(lps[i] == a.size())
            {
                int val = i - 2*a.size();
                va.push_back(val);
            }
        }

        kmp(sb, lps);
        for(int i=b.size(); i<lps.size(); i++)
        {
            if(lps[i] == b.size())
            {
                int val = i - 2*b.size();
                vb.push_back(val);
            }
        }

        vector<int> ans;

        for(int i=0; i<va.size(); i++)
        {
            auto it = lower_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
            if(it != vb.size() && abs(va[i] - vb[it])<=k){
                ans.push_back(va[i]);
                continue;
            }
            if(it != 0 && abs(va[i] - vb[it-1])<=k)
                ans.push_back(va[i]);            
        }
        return ans;
    }
};