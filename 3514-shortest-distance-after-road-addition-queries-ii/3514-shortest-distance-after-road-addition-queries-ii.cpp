class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& query) {
        set<int> dist;
        for(int i=0; i<n; i++)
            dist.insert(i);

        vector<int> ans;
        for(auto q : query){
            int u = q[0];
            int v = q[1];

            auto it = dist.upper_bound(u);
            cout << *it << endl;
            vector<int> remove;
            while(it != dist.end() && *it<v){
                remove.push_back(*it);
                it++;
            }

            for(auto it2 : remove){
                dist.erase(it2);
            }
            ans.push_back(dist.size()-1);
        }

        return ans;

    }
};