class Solution {
public:
    int powMod(long long num, int exp, int mod){
        long long res = 1;
        for(long long base = num; exp > 0; exp/=2){
            if(exp % 2 == 1){
                res = (res * base) % mod;
            }
            
            base = (base * base) % mod;
        }

        return res;
    }
    int fastmod(long long n, long long exp, int mod){
        if(exp == 0)
            return 1;
        else if(exp==1)
            return n;
        else {
            long long R = fastmod(n, exp/2, mod)%mod;
            if(exp%2==0)
                return (R%mod*R%mod)%mod;
            else 
                return (((( (R%mod) * (R%mod) ) %mod ) * (n%mod) )%mod );
        }
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1){
            return nums;
        }

        const int MOD = 1e9 + 7;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        int n = nums.size();

        unordered_map <int, int> m;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            auto [num, pos] = pq.top();
            if(m.size() == n){
                break;
            }
            
            pq.pop();
            pq.push({num * multiplier, pos});
            m[pos]++;
        }

        int e = k / n, r = k % n;

        vector<int> ans(n);
        while(!pq.empty()){
            auto [num, pos] = pq.top();
            pq.pop();

            ans[pos] = ((num % MOD) * fastmod(multiplier, e + (r >= 0 ? 1 : 0), MOD)) % MOD;
            r--;
        }

        return ans;
    }
};