class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)
            return 0;

        int k=0;
        while(pow(2, k)<=n)
            k++;
        k--;

        int j = pow(2, k);

        return pow(2, k+1) - 1 - minimumOneBitOperations(j^n);
    }
};