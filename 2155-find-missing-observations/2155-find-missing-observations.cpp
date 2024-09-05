class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int m_tot = accumulate(rolls.begin(), rolls.end(), 0);
        int rem = mean * (n+m) - m_tot;

        vector<int> ans;
        cout << rem << endl;
        if(rem > 6*n || rem < 0 || (rem/n)==0)
            return ans;

        int val = rem/n;
        int extra = rem%n;
        for(int i=0; i<n; i++){
            ans.push_back(val);
        }
        for(int i=0; i<extra; i++){
            ans[i]++;
        }   

        return ans;
    }
};