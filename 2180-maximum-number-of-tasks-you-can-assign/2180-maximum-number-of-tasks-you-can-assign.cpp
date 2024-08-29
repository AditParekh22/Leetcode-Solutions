class Solution {
public:
    bool isPossible(int mid, vector<int> &t, vector<int> &w, int p, int s){
        multiset<int> ms(w.end()-mid,w.end());

        for(int i=mid-1; i>=0; i--){
            auto it = ms.end();
            it--;
            if(*it < t[i]){
                if(!p) return false;
                it = ms.lower_bound(t[i]-s);
                if(it == ms.end()) return false;
                p--;
            }
            ms.erase(it);
        }

        return true;
    }
    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int st) {
        sort(t.begin(), t.end());
        sort(w.begin(), w.end());
        int n = t.size();
        int m = w.size();
        int s = 0, e = min(n, m);
        int mid = s + (e-s)/2;
        int ans = 0;
        while(s<=e)
        {
            if(isPossible(mid, t, w, p, st))
            {
                ans = mid;
                s = mid+1;
            }
            else
                e = mid-1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
};