class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        istringstream s(s1);
        string token;

        while(getline(s, token, ' ')) mp[token]++;

        istringstream st(s2);

        while(getline(st, token, ' ')) mp[token]++;

        for(auto it : mp)
            cout << it.first << " " << it.second << endl;
        cout << endl;

        vector<string> ans;
        
        for(auto it : mp){
            if(it.second == 1)
                ans.push_back(it.first);
        }


        return ans;
    }
};