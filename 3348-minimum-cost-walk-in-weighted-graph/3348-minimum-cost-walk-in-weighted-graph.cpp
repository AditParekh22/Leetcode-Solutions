class Solution {
public:

    void dfs(vector<vector<int>>&adj, vector<int> &vis, int node, int component)
    {
        vis[node] = component;

        for(auto it : adj[node])
        {
            if(!vis[it])
                dfs(adj, vis, it, component);
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int component = 1;

        for(int i=0; i<n; i++)
        {
            if(!vis[i]){
                dfs(adj, vis, i, component);
                component++;
            }
        }

        for(auto it: vis)
            cout << it << " " ;
        cout << endl;


        vector<int> comp_val(component, pow(2, 31)-1);
        for(int i=0;i<edges.size(); i++)
        {
            int c = vis[edges[i][0]];
            if(comp_val[c] >-1)
                comp_val[c] = comp_val[c] & edges[i][2];
        }
        vector<int> ans;

        for(auto q : query)
        {
            int u = q[0];
            int v = q[1];

            if(vis[u] != vis[v])
                ans.push_back(-1);
            else
                ans.push_back(comp_val[vis[u]]);

        }

        return ans;
    }
};