#define ll long long
class Solution {
public:
    int N = 100000;
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<ll> ans;

        bitset<100000> bset(0);
        ll sum = 0;
        bitset<100000> binit(0);
        binit.flip();

        for(int i=0; i<n; i++)
        {
            sum += nums2[i];
            if(nums1[i] == 1)
                bset[i] = 1;
        }

        for(auto q : queries)
        {
            // cout << q[0] << " " << endl;
            if(q[0] == 1)
            {
                int sz = q[2] - q[1] + 1;
                bitset<100000> btemp(binit<<sz);
                btemp = ~btemp;
                btemp = btemp<<q[1];
                bset ^= btemp;
            }
            else if(q[0] == 2)
            {
                sum += q[1] * bset.count();
            }   
            else{
                // cout << q[0] << endl;
                ans.push_back(sum);
            }

        }

        // cout << binit << endl;


        // cout << sum <<endl;

        return ans;


    }
};