class Solution {
public:
    bool isDivisibleBy7(string& s) {
        int remainder = 0;
        for (char c : s) {
            remainder = (remainder * 10 + (c - '0')) % 7;
        }
        return remainder == 0;
    }
    string largestPalindrome(int n, int k) {
        if (k == 1 || k == 3 || k == 9)
            return string(n, '9');
        else if (k == 2) {
            string ans = "8";
            if (n - 2 > 0)
                ans += string(n - 2, '9');
            if (n - 1 > 0)
                ans += '8';
            return ans;
        } 
        else if (k == 4) {
            if (n <= 4)
                return string(n, '8');
            else
                return "88" + string(n - 4, '9') + "88";
        }
        else if (k == 5) {
            string ans = "5";
            if (n - 2 > 0)
                ans += string(n - 2, '9');
            if (n - 1 > 0)
                ans += '5';
            return ans;
        } 
        else if (k == 6){
            if(n<=2)
                return string(n, '6');
            else{
                if(n&1){
                    return "8" + string((n-3)/2, '9') + "8" + string((n-3)/2, '9') + "8";
                }
                else
                    return "8" + string((n-4)/2, '9') + "77" + string((n-4)/2, '9') + "8";
            }
        }
        else if(k == 7){
            string ans = string(n, '9');
            if(n&1){
                for(char i='9';i>='0';i--){
                    ans[n/2]=i;
                    if(isDivisibleBy7(ans)){
                        return ans;
                    }
                }
            }
            else{
                
                for(char i='9';i>='0';i--){
                    ans[n/2]=i;
                    ans[n/2-1]=i;
                    if(isDivisibleBy7(ans)){
                        return ans;
                    }
                }
            }

        }
        else if(k == 8){
            if(n<=6)
                return string(n, '8');
            else 
                return "888" + string(n-6, '9') + "888";
        }
        return "";
    }
};