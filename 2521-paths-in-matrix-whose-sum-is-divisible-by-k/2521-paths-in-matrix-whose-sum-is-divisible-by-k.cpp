#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    unordered_map<ll,unordered_map<ll,unordered_map<ll, ll>>> mp;
    vector<vector<vector<int>>> dp;
    ll n, m;
    ll solve(vector<vector<int>>& grid, ll k, ll i, ll j, ll ans)
    {
        if(i == n-1 && j == m-1)
            return ((ans + grid[n-1][m-1])%k) == 0 ? 1 : 0;
    
        if(i >=n || j>=m)
            return 0;
            
        if(dp[i][j][ans] != -1)
            return dp[i][j][ans];
            
        int res = 0;
        res = (res%mod + solve(grid, k, i+1, j, (ans + grid[i][j])%k)%mod)%mod;
        res = (res%mod + solve(grid, k, i, j+1, (ans + grid[i][j])%k)%mod)%mod;

        return dp[i][j][ans] = res%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n, vector<vector<int>>(m, vector<int>(k+1,-1)));
        return solve(grid, k, 0, 0, 0);
    }
};