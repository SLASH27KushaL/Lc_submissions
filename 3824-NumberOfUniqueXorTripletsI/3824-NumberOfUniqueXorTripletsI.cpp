// Last updated: 6/26/2025, 7:52:51 PM
class Solution {
public:
int getHighest(int n) {
    if (n == 0) return 0;
    return 32 - __builtin_clz(n);
}

    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        //we need to print number of unique values of xor
  int ans=0;
  if(n>=3){
    int a=getHighest(n);
    ans=pow(2,a);
  }
  else{
   if(n==2){
    return 2;

   }
   else
   {
    return 1;
   }
  }
    return ans;
    }
};