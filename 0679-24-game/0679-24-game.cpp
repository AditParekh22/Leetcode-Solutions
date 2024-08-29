class Solution {
public:
    vector<double> getaValidOperation(double a, double b)
    {
        vector<double> arr={a+b,a-b,b-a,a*b};
        if(b != 0)
            arr.push_back(a/b);
        if(a != 0)
            arr.push_back(b/a);
        return arr;
    }
    bool solve(vector<double> arr){
        int n = arr.size();
        // cout << "n: "<< n << endl;
        if(n==1){
            // cout << arr[0]-24 << endl;
            return abs(arr[0]-24)<=0.1;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                vector<double> next;
                for(int p=0; p<n; p++){
                    if(p == i || p == j){
                        // cout << arr[p] << endl;
                        continue;
                    }
                    next.push_back(arr[p]);
                }
                // cout << "n: " << next.size() << endl;
                vector<double> operations = getaValidOperation(arr[i], arr[j]);
                
                for(auto it: operations){
                    next.push_back(it);
                    // for(auto it:  next){
                    //     cout << it << " ";
                    // }
                    // cout << endl;
                    if(solve(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> next(cards.begin(), cards.end());
        return solve(next);
        // return false;
        
    }
};