class DisjointSet{
public:
    vector<int> parent, size, rank;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    int findUPar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)  return;
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_v];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> redundantCyclicGraph(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<vector<int > >adj(n+1);
        vector<int> ans(2);

        DisjointSet ds(n);
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if(u == -1 && v == -1)
                continue;

            int x = ds.findUPar(u);
            int y = ds.findUPar(v);
            // cout << x << " " << y << endl;

            if(x == y)
            {
                ans[0] = u;
                ans[1] = v;
                break;
            }
            ds.unionByRank(u, v);
        }
        
        // for(auto it : ds.parent)
        //     cout << it << " " ;
        // cout << endl;
        return ans;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // Calculate the number of indegrees
        int n = edges.size();
        vector<int> indegree(n+1, -1);
        int edge1 = -1, edge2 = -1;
        DisjointSet ds(n);

        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
                // cout << u << " " << v << endl;
            if(indegree[v] != -1)
            {
                edge1 = indegree[v];  
                edge2 = i;          
                break;
            }
            indegree[v] = i;
        }

        cout << edge1 << " " << edge2 << endl;
        for(int i = 0 ; i < n ; i++) {
            int u = edges[i][0], v = edges[i][1];
            if(i == edge2) continue;

            if(ds.findUPar(u) == ds.findUPar(v)) {
                // cout << edge1 << endl;
                if(edge1 != -1) return edges[edge1];
                else return edges[i];
            }

            ds.unionBySize(u, v);
        }
        return edges[edge2];
    }
};