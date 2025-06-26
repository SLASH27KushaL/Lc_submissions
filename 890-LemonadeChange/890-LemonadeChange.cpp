// Last updated: 6/26/2025, 7:56:24 PM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0, count_10 = 0;

        for(int bill : bills) {
            if(bill == 5) {
                count_5++;
            }
            else if(bill == 10) {
                if(count_5 > 0) {
                    count_5--;
                    count_10++;
                } else {
                    return false;
                }
            }
            else { // bill == 20
                if(count_10 > 0 && count_5 > 0) {
                    count_10--;
                    count_5--;
                } 
                else if(count_5 >= 3) {
                    count_5 -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
