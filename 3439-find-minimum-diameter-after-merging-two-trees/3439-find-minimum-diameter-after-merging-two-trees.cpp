class Solution {
public:
    void makeGraph(vector<vector<int>> &edges, vector<vector<int> > &adj)
    {
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void findFurthest(vector<vector<int> > &adj, int node, int parent, int dist, pair<int, int> &res)
    {
        if(dist > res.first)
            res = {dist, node};

        for(auto it : adj[node])
        {
            if(it != parent)
                findFurthest(adj, it, node, dist+1, res);
        }
    }

    int findDiameter(vector<vector<int> > &adj)
    {
        pair<int, int> res1 = {INT_MIN, -1}, res2 = {INT_MIN, -1};
        findFurthest(adj, 0, -1, 0, res1);
        findFurthest(adj, res1.second, -1, 0, res2);

        return res2.first;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int> > adj1(n+1);
        vector<vector<int> > adj2(m+1);

        makeGraph(edges1, adj1);
        makeGraph(edges2, adj2);

        int dia1 = findDiameter(adj1);
        int dia2 = findDiameter(adj2);
        // cout << dia1 << " " << dia2 << endl;

        return max(dia1, max(dia2, ((dia1 + 1)/2 + (dia2 + 1)/2 + 1)));
    }
};