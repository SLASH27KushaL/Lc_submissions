// Last updated: 6/26/2025, 7:59:17 PM
class Solution {
public:
    long long mySqrt(int x) {
      long long low=0;
      long long high=pow(2,31)-1;
     while(low<=high){
        long long mid=(low+high)/2;
        if(mid*mid==x){
         return mid;
        }
        else if(mid*mid>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

     }
     return high;
    }
};