class Solution {
public:
    void findAllSubset(vector<int> &a, vector<int> &add){
        int n = a.size();

        for(int mask = 0; mask<(1<<n); mask++){
            int sum = 0;
            for(int i=0; i<n; i++){
                if(mask & (1<<i)){
                    sum += a[i];
                }
            }
            add.push_back(sum);
        }
        
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        // Dividing the array into two parts
        vector<int> left(nums.begin(), nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2, nums.end());

        // for(auto it : left)
        //     cout << it << " ";
        // cout << endl;

        // for(auto it : right)
        //     cout << it << " ";
        // cout << endl;

        // Finding all the subsets
        vector<int> sumA, sumB;
        findAllSubset(left, sumA);
        findAllSubset(right, sumB);

        // Sort them
        sort(sumA.begin(), sumA.end());
        sort(sumB.begin(), sumB.end());

        int ans = INT_MAX;

        for(int i=0; i<sumA.size(); i++){
            int t = sumA[i];
            int s = 0, e = sumB.size()-1, mid = s + (e-s)/2;;

            while(s<=e){
                int target = t + sumB[mid];
                if(target == goal)
                    return 0;
                ans = min(ans, abs(target-goal));
                if(target>goal)
                    e=mid-1;
                else
                    s=mid+1;
                mid = s + (e-s)/2;

            }


        }

        return ans;
    }
};