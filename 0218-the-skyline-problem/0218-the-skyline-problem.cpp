class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<pair<int, int>> arr;
        for(int i=0; i<b.size(); i++)
        {
            arr.push_back({b[i][0], -1*b[i][2]});
            arr.push_back({b[i][1], b[i][2]});
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();

        for(auto& [ind, height]: arr)
            cout << ind << " " << height << endl;
        cout << endl;
        vector<vector<int> > ans;
        multiset<int> mst;
        int prev = 0;

        for(auto& [ind, height]: arr)
        {
            int curr=0;
            // Height not found ==> This mean that ind is the left end
            if(height<0){
                mst.insert(abs(height));
                curr = *mst.rbegin();
                // cout << curr << endl;
                if(prev != curr)
                    ans.push_back({ind, curr});
            }
            // Found the element => This mean we are at the right edges
            else
            {
                cout << ind << " " << curr << endl;
                mst.erase(mst.find(height));
                if(mst.size() > 0)
                    curr = *mst.rbegin();
                if(prev != curr)
                    ans.push_back({ind, curr});

            }

            prev = curr;
        }

        return ans;
    }
};