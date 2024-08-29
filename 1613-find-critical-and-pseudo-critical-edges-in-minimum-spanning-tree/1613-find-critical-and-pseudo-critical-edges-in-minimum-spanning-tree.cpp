class DisjointSet{
public : 
    vector<int> rank, parent;
    DisjointSet(int n){
        rank.resize(n+1);
        parent.resize(n+1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int N;
    int Kruskal(vector<vector<int> > &arr, int ign, int add){
        int n = arr.size();
        DisjointSet ds(n);
        int wt = 0;
        int edgesConnected = 0;

        if(add != -1){
            ds.unionByRank(arr[add][0], arr[add][1]);
            wt += arr[add][2];
            edgesConnected++;
        }

        for(int i=0; i<n; i++){
            if(i != ign){
                int u = arr[i][0];
                int v = arr[i][1];
                int w = arr[i][2];
                // cout << u << " " << v << " " << wt <<  endl;

                if(ds.findUPar(u) != ds.findUPar(v)){
                    ds.unionByRank(u, v);
                    edgesConnected++;
                    wt += w;
                }
            }

        }
        if(edgesConnected != N-1)
            return INT_MAX;

        return wt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& arr) {
        N = n;
        for(int i=0; i<arr.size(); i++){
            arr[i].push_back(i);
        }
        auto comp = [&](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        };

        // Sorting the array based on wt
        sort(arr.begin(), arr.end(), comp);
        // array, ignored_edge, add_edge
        int mst = Kruskal(arr, -1, -1);
        vector<int> crit, psd;

        for(int i=0; i<arr.size(); i++){
            if(Kruskal(arr, i, -1) > mst)
                crit.push_back(arr[i][3]);
            else if(Kruskal(arr, -1, i) == mst)
                psd.push_back(arr[i][3]);
        }

        // vector<vector<int> > ans;
        sort(crit.begin(), crit.end());
        sort(psd.begin(), psd.end());


        // return ans;
        return {crit, psd};

    }
};