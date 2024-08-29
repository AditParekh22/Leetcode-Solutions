class Solution {
public:
    bool solve(string A, string B, unordered_map<string, bool> &mp)
    {
        int n = A.size();
        if(A == B)
            return true;
        if(n == 1)
            return false;
        string key = A + " " + B;
        if(mp.count(key))
            return mp[key];
        for(int i=1; i<n; i++)
        {
            if(solve(A.substr(0, i), B.substr(0, i), mp) && 
                solve(A.substr(i), B.substr(i), mp) )
                return mp[key] = true;
                
            if(solve(A.substr(0, i), B.substr(n-i), mp) && 
                solve(A.substr(i), B.substr(0, n-i), mp))
                return mp[key] = true;
        }
        return mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
    
        unordered_map<string, bool> mp;
        return solve(s1, s2, mp);
    }
};