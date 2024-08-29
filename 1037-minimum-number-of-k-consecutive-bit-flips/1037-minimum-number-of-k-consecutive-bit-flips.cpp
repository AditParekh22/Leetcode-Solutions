class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        int ans = 0;

        for(int i=0; i<n; i++){
            while(!q.empty() && q.front()+k-1<i)    
                q.pop_front();
            if((nums[i] + q.size())%2 == 0){
                if(i + k > n)
                    return -1;
                q.push_back(i);
                ans++;

            }
        }

        return ans;
        
    }
};