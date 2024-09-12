class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st;
        for(auto ch : allowed)
            st.insert(ch);

        int cnt = 0;
        for(auto word : words){
            bool flag = true;
            for(auto ch : word){
                if(st.find(ch) == st.end()){
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }

        return cnt;
    }
};