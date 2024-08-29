class Solution {
public:
    int n;
    vector<int> bit;

    void update(int val, int id)
    {
        while(id <= n){
            bit[id] += val;
            id += (id & -id);
        }
    }
    int query(int id)
    {
        int ans = 0;
        while(id>0){
            ans += bit[id];
            id -= (id & -id);
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        bit = vector<int>(n+1, 0);

        vector<pair<int, int> > v;
        for(int i=0;i<n; i++)
        {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());


        vector<int> ans(n, 0);

        for(auto& [el, id] : v)
        {
            update(1, id+1);
            ans[id] = query(n) - query(id+1);
        }
        return ans;
    }
};