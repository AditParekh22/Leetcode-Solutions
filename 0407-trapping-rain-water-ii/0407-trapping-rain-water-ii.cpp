class Solution {
public:
    bool checkRange(int x, int y, int n, int m){
        if(x<0 || y<0 || x>=n || y>=m)
            return false;
        return true;
    }
    int trapRainWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        memset(vis, 0,sizeof(vis));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        for(int i=0; i<n; i++){
            pq.push({grid[i][0], {i, 0}});
            pq.push({grid[i][m-1], {i, m-1}});
            // cout << grid[i][0] << " " << grid[i][m-1] << endl;
            vis[i][0] = 1;
            vis[i][m-1] = 1;
        }
        for(int j=1; j<m-1; j++){
            pq.push({grid[0][j], {0, j}});
            pq.push({grid[n-1][j], {n-1, j}});
            // cout << grid[0][j] << " " << grid[n-1][j] << endl;
            vis[0][j] = 1;
            vis[n-1][j] = 1;
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, -1, 0, 1};

        
        int maxi = 0, ans=0;
        while(!pq.empty()){
            int ht = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            cout << ht << " " << x << " " << y << endl; 
            pq.pop();
            maxi = max(maxi, ht);

            for(int i=0; i<4; i++){
                int nx = x + delRow[i];
                int ny = y + delCol[i];

                if(checkRange(nx, ny, n , m) && !vis[nx][ny]){
                    pq.push({grid[nx][ny], {nx, ny}});
                    vis[nx][ny] = 1;
                    if(grid[nx][ny] < maxi)
                        ans += (maxi - grid[nx][ny]);
                }
            }

        }
        return ans;
    }
};