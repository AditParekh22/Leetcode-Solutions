class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {

        map<pair<char,char>,int>mp;
        for(auto it:mappings){
            mp[{it[0],it[1]}] = 1;
        }

        auto ismatch = [&](int ind){
            for(int i=0;i<sub.size();i++){
                if(sub[i] == s[i+ind] ||  mp.count({sub[i],s[i+ind]})){
                    continue;
                }
                else return false;
            }
            return true;
        };

        for(int i=0;i<=s.size()-sub.size();i++){
            if(ismatch(i)) return true;
        }

        return false;
    }
};