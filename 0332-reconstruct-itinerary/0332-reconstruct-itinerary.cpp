class Solution {
public:
    void dfs(map<string, vector<string>> &mp, vector<string> &ans, string node)
    {
        // cout << node << endl;
        for(int i=0; i<mp[node].size(); i++)
        {
            // cout << mp[node][i] << endl;
            string temp = mp[node][i];
            if(mp[node][i] != "1"){
                mp[node][i] = "1";
                dfs(mp, ans, temp);
            }
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        map<string, vector<string>> mp;

        for(int i=0; i<t.size(); i++)
        {
            string u = t[i][0];
            string v = t[i][1];

            mp[u].push_back(v);
        }

        for(auto it: mp)
        {
            sort(mp[it.first].begin(), mp[it.first].end());
        }

        // for(auto it: mp)
        // {
        //     cout << it.first << "->";
        //     // sort(it.second.begin(), it.second.end());
        //     for(auto it2 : it.second)
        //         cout << it2 << " ";
        //     cout << endl;
        // }

        vector<string> ans;
        dfs(mp, ans, "JFK");

        reverse(ans.begin(), ans.end());
        
        return ans;

    }
};