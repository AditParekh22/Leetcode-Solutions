class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_cnt = 0, ten_cnt = 0;
        int n = bills.size();

        for(int i=0; i<n; i++){
            if(bills[i] == 5)
                five_cnt++;
            else if(bills[i] == 10){
                if(five_cnt == 0)
                    return false;
                else
                    five_cnt--;
                ten_cnt++;
            }
            else{
                if(ten_cnt == 0){
                    if(five_cnt<3)
                        return false;
                    else
                        five_cnt-=3;
                }
                else{
                    ten_cnt--;
                    if(five_cnt == 0)
                        return false;
                    else
                        five_cnt--;
                }
            }
        }

        return true;

    }
};

/*
Good implementation
int lemonadeChange(vector<int> bills) {
    int five = 0, ten = 0;
    for (int i : bills) {
        if (i == 5) five++;
        else if (i == 10) five--, ten++;
        else if (ten > 0) ten--, five--;
        else five -= 3;
        if (five < 0) return false;
    }
    return true;
}
*/