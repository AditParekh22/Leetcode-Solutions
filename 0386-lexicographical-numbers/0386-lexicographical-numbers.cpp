class Solution {
public: 
    void fun(int n, int node, vector<int> &ans){
        ans.push_back(node);
        for(int i=0; i<=9; i++){
            int val = node*10+i;
            if(val <=n)
                fun(n, val, ans);
            else
                break;

        }

    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i=1; i<=min(9, n); i++){
            fun(n, i, ans);
        }

        return ans;
        
    }   
};