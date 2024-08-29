#define ll long long

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        if(k==1){
            return 0;
        }
        int n = nums.size();
        
        // store index of all one in sorted order
        vector<int> index;
        for(int i=0;i<n;i++){
            if(nums[i]){
                index.push_back(i);
            }
        }

        // calculate prefix sum of index array
        vector<ll> prefix;
        ll sum = 0;
        for(int x : index){
            sum += x;
            prefix.push_back(sum);
        }

        // now take window of k size consecutively
        int i=0,j=k-1;
        ll radius = (k%2 ? k/2 : (k-2)/2);
        ll ans = 1e15;
        while(j<index.size()){
            ll temp = 0;
            if(k%2){
                int pivot = (i+j)/2;
                temp = prefix[j]-prefix[pivot] -
                        ((pivot>0 ? prefix[pivot-1] : 0)-(i>0 ? prefix[i-1] : 0)) -
                        radius*(radius+1);
            }
            else{
                int pivot = (i+j)/2;
                temp = prefix[j]-prefix[pivot] -
                        ((pivot>0 ? prefix[pivot-1] : 0)-(i>0 ? prefix[i-1] : 0)) - index[pivot] -
                        radius*(radius+1) - (radius+1);
            }
            ans = min(ans, temp);
            i++;j++;
        }

        return ans;
    }
};