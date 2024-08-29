class Solution {
public:
    int minRefuelStops(int target, int cur, vector<vector<int>> s) {
        int n = s.size();
        priority_queue<pair<int, int> > pq;
        for(auto it : s)
            pq.push({it[1], it[0]});
        int curr_reach = cur;
        int stops = 0;
        while(!pq.empty()){
            if(curr_reach >= target)
                return stops;
            vector<pair<int, int> > rem;
            // int fuel = pq.top().first;
            // int dist = pq.top().second;
            while(!pq.empty() && pq.top().second>curr_reach){
                rem.push_back(pq.top());
                pq.pop();
            }
            if(pq.empty())
                return -1;
            else{
                curr_reach += pq.top().first;
                pq.pop();
                stops++;
            }
            for(auto it : rem)
                pq.push(it);
        }
        if(curr_reach< target)
            return -1;
        return stops;

    }
};