#define ll long long
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        priority_queue<ll> h, v;
        for(auto it:horizontalCut)
            h.push(it);

        for(auto it:verticalCut)
            v.push(it);

        ll h_cnt = 1, v_cnt = 1;
        ll ans = 0;
        while(h.size()>0 && v.size()>0)
        {
            ll h_top = h.top();
            ll v_top = v.top();

            if(v_top >= h_top)
            {
                h_cnt++;
                ans += (v_top * v_cnt);
                v.pop();
            }
            else
            {
                v_cnt++;
                ans += (h_top * h_cnt);
                h.pop();
            }
        }
        while(h.size()>0)
        {
            ans += (h.top() * h_cnt);
            h.pop();
        }
        while(v.size()>0)
        {
            ans += (v.top() * v_cnt);
            v.pop();
        }

        return ans;
    }
};