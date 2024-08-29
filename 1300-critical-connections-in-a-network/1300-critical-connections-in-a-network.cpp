class Solution {
public:
    int time = 0;
    void dfs(vector<vector<int> > &adj, vector<int> &vis, vector<int> &low, vector<int> &timer, int node, int parent,     
            vector<vector<int>> &cc)
    {
        vis[node] = 1;
        low[node] = time;
        timer[node] = time;
        time++;

        for(auto it : adj[node])
        {
            if(it == parent)
                continue;
            if(!vis[it])
            {
                dfs(adj, vis, low, timer, it, node, cc);

                low[node] = min(low[node], low[it]);

                if(low[it] > timer[node])
                    cc.push_back({it, node});
            }
            else
                low[node] = min(low[node], low[it]);
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int> >adj(n+1);

        for(int i=0; i<c.size(); i++)
        {
            int u = c[i][0];
            int v = c[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> low(n+1);
        vector<int> timer(n+1);
        vector<int> vis(n+1, 0);
        vector<vector<int> > cc;

        dfs(adj, vis, low, timer, 0, -1, cc);

        return cc;

    }
};