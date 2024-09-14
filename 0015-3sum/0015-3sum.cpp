#define f first
#define s second
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();


        sort(arr.begin(), arr.end());
        set<vector<int>> temp;
        vector<vector<int> > ans;
        for(int i=0; i<n; i++){
            int left = i+1;
            int right = n-1;
            // cout << left << " " << right << " " << i << endl;
            while(left<right){
                if(arr[left]+ arr[i] + arr[right] == 0){
                    vector<int> t = {arr[left], arr[i], arr[right]};
                    sort(t.begin(), t.end());
                    temp.insert(t);
                    left++;
                    right--;
                }
                else if(arr[left] + arr[i] + arr[right] > 0)
                    right--;
                else
                    left++;
            }
        }
        for(auto it : temp)
            ans.push_back(it);
        return ans;
    }
};