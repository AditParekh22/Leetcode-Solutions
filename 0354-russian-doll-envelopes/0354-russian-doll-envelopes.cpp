class Solution {
public:
    static bool comp(vector<int> &a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else{
            return a[0]<b[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end(), comp);
        for(auto it : e)
            cout << it[0] << " " << it[1] << endl;
        vector<int> h;

        h.push_back(e[0][1]);
        for(int i=1; i<n; i++)
        {
            if(h.back() < e[i][1])
                h.push_back(e[i][1]);
            else
            {
                int ind = lower_bound(h.begin(), h.end(), e[i][1]) - h.begin();
                h[ind] = e[i][1];
            }

        }
        return h.size();


    }
};