class Solution {
public:
    bool cycleDetect(vector<vector<int> > &adj, vector<int> &vis, vector<int> &pathVis, int node){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto child : adj[node]){
            if(!vis[child]){
                if(cycleDetect(adj, vis, pathVis, child))
                    return true;
            }
            else if(pathVis[child])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(int i=0; i<p.size(); i++){
            int u = p[i][0];
            int v = p[i][1];

            adj[v].push_back(u);
        }

        vector<int> vis(n, 0), pathVis(n,0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(cycleDetect(adj, vis, pathVis, i))
                    return false;
            }
        }
        return true;


    }
};