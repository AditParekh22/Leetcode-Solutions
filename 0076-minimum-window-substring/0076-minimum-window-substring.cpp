class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;

        for(int i=0; i<t.size(); i++)
            mp[t[i]]++;
        int i=0, j=0, cnt = t.size();
        string res = "";
        int minLen = INT_MAX, minInd = 0;

        while(j<s.size())
        {
            if(mp[s[j]] > 0)
                cnt--;
            mp[s[j]]--;

            while(cnt == 0)
            {
                if(j-i+1 < minLen)
                {
                    minInd = i;
                    minLen = j-i+1;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0)
                    cnt++;  
                i++;   
            }


            j++;
        }
        cout << minLen << endl;
        return minLen == INT_MAX? "" : s.substr(minInd, minLen);
        
    }
};