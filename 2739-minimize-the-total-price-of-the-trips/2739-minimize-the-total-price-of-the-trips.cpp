class Solution {
public:

    void makeContri(int node, vector<int> &curr, vector<int> &contri, int end, vector<vector<int>> &adj, int parent)
{
    curr.push_back(node);

    if (end == node)
    {
        for (auto it : curr)
        {
            contri[it]++;
        }
        curr.pop_back();
        return;
    }

    for (auto it2 : adj[node])
    {
        if (it2 != parent)
            makeContri(it2, curr, contri, end, adj, node);
    }

    curr.pop_back();
}
int dp[51][2];
int dfs(vector<int> &contri, vector<vector<int>> &adj, vector<int> &taxes, int node, int parent, bool prevSet = false)
{
    int res1 = (contri[node] *taxes[node])/2;
    int res2 = (contri[node] *taxes[node]);

    // cout << node << " " <<res1 << " " << res2 << endl;
    if(dp[node][prevSet] != -1)
        return dp[node][prevSet];

    // Notake : we are not dividing the values by half
    for(auto it : adj[node])
    {
        if(it != parent)
        {
            res2 += dfs(contri, adj, taxes, it, node, 0);
        }
    }

    // If we have already reduced the values of parent node we cannot reduce the value of curr node
    if(prevSet == true)
        return dp[node][prevSet] = res2;
    // Take
    for(auto it : adj[node])
    {
        if(it != parent)
        {
            res1 += dfs(contri, adj, taxes, it, node, 1);
        }
    }
    return dp[node][prevSet] = min(res1, res2);

}
int minTax(int n, vector<int> &taxes, vector<vector<int>> &adj, vector<vector<int>> &trips)
{
    vector<int> contri(n+1, 0);

    for (auto it : trips)
    {
        vector<int> curr;
        makeContri(it[0], curr, contri, it[1], adj, -1);
    }

    // cout << "contribution" << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << contri[i] << " ";
    // }
    // cout << endl;
    memset(dp, -1, sizeof(dp));
    return dfs(contri, adj, taxes, 1, -1, 0);
}
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        if(n == 1)  
            return price[0]/2;
        vector<vector<int>> adj(n);

        for (int i = 0; i < n-1; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            // cout << u << " " << v << endl;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return minTax(n, price, adj, trips);
    }
};