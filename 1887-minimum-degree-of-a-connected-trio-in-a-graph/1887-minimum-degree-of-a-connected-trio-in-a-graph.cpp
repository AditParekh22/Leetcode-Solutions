class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int> > m(n+1, vector<int>(n+1));
        vector<int> d(n+1, 0);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            m[u][v] = 1;
            m[v][u] = 1;

            d[u]++;
            d[v]++;
        }

        int mini = INT_MAX;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                for(int k=j+1; k<=n; k++){
                    if(m[i][j] ==1 && m[j][k] == 1 && m[k][i] ==1)
                        mini = min(mini, d[i] + d[j] + d[k]-6);
                }
            }
        }

        if(mini == INT_MAX)
            return -1;
        return  mini;
    }
};