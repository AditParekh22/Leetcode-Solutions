class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> pref(n), suff(n);
        pref[0] = h[0];
        suff[n-1] = h[n-1];
        for(int i=1; i<n; i++){
            pref[i] = max(pref[i-1], h[i]);
            suff[n-i-1] = max(suff[n-i], h[n-i-1]);
        }   
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            cout << pref[i] << " " << suff[i] << endl;
            ans += min(pref[i], suff[i]) - h[i];
        }

        return ans;
    }
};