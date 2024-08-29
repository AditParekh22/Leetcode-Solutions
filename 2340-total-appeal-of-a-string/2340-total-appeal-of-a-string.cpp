#define ll long long
class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        map<char, vector<int> > mp;

        for(int i=0; i<s.size(); i++)
            mp[s[i]].push_back(i);
        ll ans = 0;

        // for(auto& [ch, ind]: mp)
        // {
        //     mp[ch].push_back(n);
        //     // cout << ch << "-> ";
        //     for(int i=0; i<ind.size(); i++)
        //     {
        //         cout <<ind[i] << " ";
        //     }
        //     cout << endl; 
        // }
        for(auto& [ch, ind]: mp)
        {
            mp[ch].push_back(n);
            // cout << ch << "->" << endl;
            int prev = ind[0];
            for(int i=1; i<ind.size(); i++)
            {
                cout << (prev+1) * (ind[i]-prev) << endl; 
                ans += (prev+1) * (ind[i]-prev);
                prev = ind[i];
            }
        }
        return ans;
    }
};