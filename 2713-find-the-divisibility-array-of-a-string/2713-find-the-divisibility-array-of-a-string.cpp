class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long int num = 0;

        vector<int> ans;
        for(auto ch : word){
            int el = ch - '0';
            num = num*10 + el;

            if(num%m == 0)
                ans.push_back(1);
            else
                ans.push_back(0);
            num = num%m;

        }

        return ans;
    }
};