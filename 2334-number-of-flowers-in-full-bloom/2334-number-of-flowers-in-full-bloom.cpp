class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for(auto it : flowers){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> ans;
        for(auto day : people){
            int s = upper_bound(start.begin(), start.end(), day) - start.begin();
            int e = lower_bound(end.begin(), end.end(), day) - end.begin();

            ans.push_back(s-e);
        }
        return ans;

    }
};