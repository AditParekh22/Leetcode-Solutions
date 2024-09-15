class Solution {
public:
    int findTheLongestSubstring(string s) {
        int c_m[26] = {1, 0, 0, 0, 2, 0, 0, 0,  4, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0};
        int mask = 0, res = 0;
        vector<int> m(32, -1);
        for (int i = 0; i < s.size(); ++i) {
            mask ^= c_m[s[i] - 'a'];
            if (mask != 0 && m[mask] == -1)
                m[mask] = i;
            // for(auto it : m)
            //     cout << it << " ";
            // cout << endl;
            res = max(res, i - m[mask]);
        }
        return res;
    }
};