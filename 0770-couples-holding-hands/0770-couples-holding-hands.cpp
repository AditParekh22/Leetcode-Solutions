class Solution {
public:
    bool cycleDetect(vector<vector<int> > &adj, vector<int> &vis, int node, int parent)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it]){
                if(cycleDetect(adj, vis, it, node))
                    return true;
            }
            else if(it != parent)
                return true;
        }
        return false;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        // Stores which couch aperson is in
        map<int,int> mp;

        for(int i=0; i<row.size(); i++)
        {
            mp[row[i]] = i/2;
        }
        for(auto it: mp)
            cout << it.first << " " << it.second << endl;

        set<pair<int,int> > edges;
        for(int i=0; i<n; i+=2)
        {
            int u = mp[i];
            int v = mp[i+1];
            if(u == v)
                continue;

            edges.insert({u, v});
        }

        vector<vector<int> > adj(n);
        for(auto it : edges)
        {
            int u = it.first;
            int v = it.second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = edges.size();
        vector<int> vis(n, 0);
        // cycleDetect(adj, vis, i, -1);
        for(int i=0; i<n; i++)
        {
            if(!vis[i] && cycleDetect(adj, vis, i, -1)){
                ans--;
            }
        }
        
        
        return ans;
        
    }
};