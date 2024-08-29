#define ll long long
class Solution {
public:
    ll delRow[4] = {-1, 0, 1, 0};
    ll delCol[4] = {0, 1, 0, -1};

    ll dfs(vector<vector<int> > &mat, ll x, ll y, vector<vector<ll> > &dist)
    {
        dist[x][y] = 0;
        for(int i=0; i<4; i++)
        {
            ll nx = delRow[i] + x;
            ll ny = delCol[i] + y;

            if(nx<0 || ny<0 || nx>=mat.size() || ny>=mat[0].size())
                continue;

            if(mat[nx][ny] > mat[x][y] && dist[nx][ny] != -1)
                dist[x][y] = max(dist[x][y], 1+dist[nx][ny]);
            else if(mat[nx][ny] > mat[x][y])
                dist[x][y] = max(dist[x][y], 1 + dfs(mat, nx, ny, dist));
        }
        return dist[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        ll maxi = INT_MIN;

        vector<vector<ll> > dist(n, vector<ll>(m, -1));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dist[i][j] == -1)
                    dist[i][j] = dfs(matrix, i, j, dist);

                maxi = max(maxi, dist[i][j]);
            }
        }

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return maxi+1;
    }
};