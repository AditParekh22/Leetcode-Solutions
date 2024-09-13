class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref(n+1);
        pref[0] = 0;
        for(int i=1; i<=n; i++){
            pref[i] = arr[i-1] ^ pref[i-1];
        }
        // for(auto it : pref)
            // cout << it << " ";
        // cout << endl;

        vector<int> ans;
        for(auto q : queries){
            int lower = q[0];
            int upper = q[1]+1;
            // cout << pref[upper] << " " << pref[lower] << endl;
            ans.push_back(pref[upper] ^ pref[lower]);
        }

        return ans;
    }
};