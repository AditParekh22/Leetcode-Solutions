#define f first
#define s second
class Solution {
public:
    void leftSmallerEle(vector<int> &arr, vector<int> &left){
        int n = arr.size();
        stack<pair<int, int> > st;
        for(int i=0; i<n; i++){
            // cout << i << endl;
            if(st.empty()){
                // cout << "H" << endl;
                left.push_back(-1);
            }
            else if(st.top().f < arr[i]){
                // cout << "K" << endl;
                left.push_back(st.top().s);
            }
            else{
                while(!st.empty() && st.top().f >= arr[i])
                    st.pop();

                if(st.empty()){
                    // cout << "L" << endl;
                    left.push_back(-1);
                }
                else if(st.top().f < arr[i]){
                    // cout << "G" << endl;
                    left.push_back(st.top().s);
                }
            }
            st.push({arr[i], i});
        }
    }

    void rightSmallerEle(vector<int> &arr, vector<int> &right){
        int n = arr.size();
        stack<pair<int, int> > st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().f >= arr[i])
                st.pop();

            if(st.empty()){
                // cout << "L" << endl;
                right.push_back(n);
            }
            else if(st.top().f < arr[i]){
                // cout << "G" << endl;
                right.push_back(st.top().s);
            }
            st.push({arr[i], i});
        }
        reverse(right.begin(), right.end());
    }
    int maxAreaHistogram(vector<int> arr){
        int n = arr.size();
        vector<int> left, right;
        leftSmallerEle(arr, left);
        rightSmallerEle(arr, right);
    

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(ans, (right[i] - left[i]-1) * arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp(m, 0);
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0')
                    temp[j] = 0;
                else
                    temp[j] += (matrix[i][j] - '0');
            }

            ans = max(ans, maxAreaHistogram(temp));
        }
        
        return ans;
    }

};