// Last updated: 7/20/2025, 7:13:56 PM
class Solution {
public:
    bool checkDivisibility(int n) {
       int s1=0;
    long long p1=1;
        int t=n;
        while(t){
        long long s=t%10;
        s1+=s;
        p1*=s;
        t/=10;
        }
        int r=(p1+s1);
        return n%r==0;
    }
};