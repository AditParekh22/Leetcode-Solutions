#define ll long long
class Solution {
public:
    void dijkstra(vector < vector<pair<ll, ll>>> &adj, int src, int dest, vector<ll> &dist) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            ll wt = it.first;
            ll node = it.second;
            pq.pop();
            // cout << node << " " << wt << endl;

            for (auto it : adj[node]) {
                ll v = it.first;
                ll w = it.second;

                if (wt + w < dist[v]) {
                    dist[v] = wt + w;
                    pq.push({wt + w, v});
                }
            }
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<ll, ll>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            ll u = edges[i][0];
            ll v = edges[i][1];
            ll wt = edges[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<ll> distA(n, 1e9);
        vector<ll> distB(n, 1e9);
        vector<bool> ans(edges.size(), false);

        dijkstra(adj, 0, n-1, distA);

        if(distA[n-1] == 1e9)
            return ans;
        ll minDist = distA[n-1];
        cout << minDist << endl;
        
        dijkstra(adj, n-1, 0, distB);

        // for(auto it: distB)
        //     cout << it << " ";
        // cout << endl;

        for(int i=0; i<edges.size(); i++)
        {
            vector<int> &e = edges[i];
            if(distA[e[0]] + distB[e[1]] + e[2] == minDist || distA[e[1]] + distB[e[0]] + e[2] == minDist)
                ans[i] = true;
        }
        
        return ans;
    }
};