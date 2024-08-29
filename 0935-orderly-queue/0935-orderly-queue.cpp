class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
            string temp=S;
            S= S+ S;
            for(int i=1;i<temp.size();i++){
                temp=min(temp,S.substr(i,temp.size()));
            }
            return temp;
    }
};