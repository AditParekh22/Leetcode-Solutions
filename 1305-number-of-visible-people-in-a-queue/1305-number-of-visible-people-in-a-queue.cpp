class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        stack<pair<int, int> > st;
        vector<int> ans;
        int n = h.size();
        for(int i=n-1; i>=0; i--)
        {
            if(st.size() == 0)
                ans.push_back(0);
            else if(st.top().first>h[i])
                ans.push_back(st.top().second-i);
            else if(st.top().first < h[i]){
                int cnt = 0;
                while(st.size() > 0 && st.top().first < h[i]){
                    st.pop();
                    cnt++;
                }
                if(st.size() == 0)
                    ans.push_back(cnt);
                else
                    ans.push_back(cnt+1);
            }

            st.push({h[i], i});
        }
        reverse(ans.begin(), ans.end());

        return ans;

        
    }
};