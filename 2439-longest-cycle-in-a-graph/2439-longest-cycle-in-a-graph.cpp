class Solution {
public:
    int ans = -1;
    void dfs(vector<int> &edges, vector<int> &vis, int node, map<int, int> &mp)
    {
        vis[node] = 1;
        int child = edges[node];

        if(child!=-1 && !vis[child])
        {
            mp[child] = mp[node] + 1;
            dfs(edges, vis, child, mp);
        }
        else if(child != -1 && mp.find(child) != mp.end())
            ans = max(ans, mp[node] - mp[child] + 1);

    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                map<int,int> mp;
                mp[i] = 1;
                dfs(edges, vis, i, mp);
            }
        }
        return ans;

    }
};