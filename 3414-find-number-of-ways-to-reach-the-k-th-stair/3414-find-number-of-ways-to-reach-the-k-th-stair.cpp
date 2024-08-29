#define ll long long
class Solution {
public:
    unordered_map<ll, unordered_map<ll, unordered_map<ll, ll> > > dp;
    ll solve(ll k, ll ind, ll jump, ll backPoss)
    {
        if(ind > k && backPoss == 0)
            return 0;
        if(jump>31)
            return 0;
        if(dp.count(ind) && dp[ind].count(backPoss) && 
                            dp[ind][backPoss].count(jump))
            return dp[ind][backPoss][jump];

        ll val = pow(2, jump);
        ll ans = (ind == k) ? 1 : 0;
        
        ans += solve(k, ind + val, jump+1, 1);
        if(backPoss)
            ans += solve(k, ind-1, jump, 0); 

        return dp[ind][backPoss][jump] = ans;
    }
    int waysToReachStair(int k) {
        return solve(k, 1, 0, 1);
    }
};