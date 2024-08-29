class Solution {
public:
    int solve(vector<vector<int>>& A, int n, int m, int i, int j,
              vector<vector<int>>& dp) {
        if (i >= A.size() || j >= A[0].size())
            return 1e9;
        if (i == n - 1 && j == m - 1) {
            if (A[i][j] < 0)
                return dp[i][j] = abs(A[i][j]) + 1;
            return dp[i][j] = 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = solve(A, n, m, i + 1, j, dp);
        int right = solve(A, n, m, i, j + 1, dp);

        int future_health = min(right, down);
        int health_needed = future_health - A[i][j];
        if (health_needed > 0)
            return dp[i][j] = health_needed;
        else
            return dp[i][j] = 1;
    }
    int calculateMinimumHP(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<vector<int> > dp(n, vector<int>(m, -1));
        return solve(A, n, m, 0, 0, dp);
    }
};