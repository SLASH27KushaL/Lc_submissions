// Last updated: 6/26/2025, 8:00:07 PM
class Solution {
public:
    int reverse(int x) {
        long long num=0;
        while(x && num<=INT_MAX){
            int val=x%10;
            num=num*10+val;
            if(num>=INT_MAX || num<=INT_MIN){
                return 0;
            }
            x/=10;
        }
      
        return num;
    }
};