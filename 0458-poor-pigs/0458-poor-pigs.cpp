class Solution {
public:
    int poorPigs(int buckets, int die, int test) {
        int rounds = test / die;
        int pigs = 0;
        while(true)
        {
            long long val = pow(rounds+1, pigs);
            if(val>=buckets)
                return pigs;
            pigs++;
        }
    }
};