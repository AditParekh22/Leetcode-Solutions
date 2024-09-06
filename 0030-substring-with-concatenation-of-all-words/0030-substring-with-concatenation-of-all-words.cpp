class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int>  cnt;
        for(auto w : words)
            cnt[w]++;
        int n = s.size(), m = words[0].size();
        vector<int> ans;
        for(int k=0; k<m; k++){
            cout << "k : " << k << endl; 
            unordered_map<string, int>  seen;
            int left = k, currLen = 0;
            for(int i=left; i<n; i+=m){
                string curr = s.substr(i, m);
                cout << i << " " << curr << endl;
                if(cnt.count(curr)){
                    seen[curr]++;
                    currLen++;
                    while(seen[curr] > cnt[curr]){
                        string frt = s.substr(left, m);
                        cout << "\t" << frt << endl;
                        seen[frt]--;
                        currLen--;
                        left+=m;
                    }
                }
                else{
                    seen.clear();
                    currLen = 0;
                    left = i+m;
                }

                if(currLen == words.size()){
                    ans.push_back(left);
                    seen[s.substr(left, m)]--;
                    currLen--;
                    left += m;
                }
            }
            
        }
        return ans;
    }
};