class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int mini = 0, maxi = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                maxi++;
                mini++;
            }
            else if(s[i] == ')'){
                maxi--;
                mini--;
            }
            else{
                mini--;
                maxi++;
            }

            if(mini<0)
                mini = 0;
            if(maxi<0)
                return false;
        }
        // cout << mini << " " << maxi << endl;
        return mini==0;
        
    }
};