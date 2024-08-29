class Solution {
public:
    int n, m;
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, -1, 0, 1};
    int dp[51][51][2501];
    int vis[51][51];
    bool check(int x, int y){
        if(x<0 || y<0 || x>=n || y>=m)
            return false;
        return true;
    }
    int solve(vector<vector<int> > &grid, int i, int j, int t){
        if(i == n-1 & j== m-1)
            return t >= grid[n-1][m-1] ? t : grid[n-1][m-1];
        if(dp[i][j][t] != -1)
            return dp[i][j][t];
        // cout << i << " " << j << " " << t << endl;

        int ans = INT_MAX;
        for(int p=0; p<4; p++){
            int nx = i + delRow[p];
            int ny = j + delCol[p];

            // cout << nx << " p " << ny << endl;

            if(!check(nx, ny) || vis[nx][ny])
                continue;

            int val = max(t, max(grid[i][j], grid[nx][ny]));
            vis[nx][ny] = 1;
            ans = min(ans, solve(grid, nx, ny, val));
            vis[nx][ny] = 0;
        }
        return dp[i][j][t] = ans;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        return solve(grid, 0, 0, 0);
    }
};