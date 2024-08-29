class Solution {
public:
    int f(vector<int> &A, int B)
    {
        int n = A.size();
        map<int, int> mp;
        int j = 0;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            mp[A[i]]++;
            while(mp.size() > B)
            {
                // cout << j << " p " << A[i] <<  endl;
                mp[A[j]]--;
                if(mp[A[j]] == 0)
                    mp.erase(A[j]);
                // cout << j << " t " << mp.size() <<  endl;
                j++;
            }
            if(mp.size() <= B)
                ans += (i-j+1);

        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
        
    }
};