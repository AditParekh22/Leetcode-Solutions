class Solution {
public:
    string decimalToBinary(string x){
        int num = stoi(x);
        string res = "";
        while(num>0){
            res += (num%2) ? '1' : '0';
            num = num/2;
        }
        reverse(res.begin(), res.end());
        return res;

    }
    string convertDateToBinary(string date) {
        int n = date.size();
        int prev = 0;
        // cout << decimalToBinary("7") << endl;
        string ans = "";
        for(int i=0; i<n; i++){
            if(date[i] == '-')
            {
                string sub = date.substr(prev, i-prev);
                ans += decimalToBinary(sub) + '-';
                cout << sub << endl;
                prev = i+1;
            }
        }
        string sub = date.substr(prev, n-prev);
        cout << sub << endl;
        ans += decimalToBinary(sub);
        return ans;
    }
};