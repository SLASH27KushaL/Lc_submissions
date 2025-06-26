// Last updated: 6/26/2025, 7:58:01 PM
class Solution {
public:
int next(int n){
    int sum=0;
    while(n){
        int rem=n%10;
        n/=10;
        sum+=(rem*rem);

    }
    return sum;
}

public:
    bool isHappy(int n) {
    map<int,int>hash;
        while(n!=1){
      n=next(n);
      if(hash[n]!=0){
        return false;
      }
      else{
        hash[n]++;
      }
    }
    return true;}
};