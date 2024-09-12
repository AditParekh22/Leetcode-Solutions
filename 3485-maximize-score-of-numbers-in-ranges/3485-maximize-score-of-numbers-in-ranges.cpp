class Solution {
public:
    bool isPossible(vector<int> &start, int d, int mid){
        long long  prev=start[0];
        for(int i=1 ; i<start.size(); i++){
            long long int next=max(prev+mid, (long long)start[i]);
            if (next > start[i] + d) { 
                return false;
            }
            prev=next;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());

        int s = 0, e = start.back()-start.front()+d, mid = s + (e-s)/2;

        int ans = 0;
        while(s<=e){
            if(isPossible(start, d, mid)){
                ans = mid;
                s = mid+1;
            }
            else
                e = mid-1;
            mid = s + (e-s)/2;
        }

        return ans;
    }
};