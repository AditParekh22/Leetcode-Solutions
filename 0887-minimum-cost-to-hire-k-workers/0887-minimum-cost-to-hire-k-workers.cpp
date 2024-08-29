#define f first
#define s second
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wages, int k) {
        vector<pair<double, int>> arr;
        int n = quality.size();

        for(int i=0; i<n; i++){
            double ratio = wages[i]/(double)quality[i];
            arr.push_back({ratio, quality[i]});
        }
        sort(arr.begin(), arr.end());

        for(auto it :  arr)
            cout << it.f << " " << it.s << endl;
        priority_queue<pair<int, double> > pq;
        int total = 0;
        double ans = 1e9;
        for(auto& [ratio, q] : arr){
            pq.push({q, ratio});
            total += q;
            if(pq.size() == k){
                ans = min(ans, total * ratio); 
                total -= pq.top().f;
                pq.pop();
            }
        }

        return ans;

    }
};