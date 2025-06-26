// Last updated: 6/26/2025, 7:58:04 PM
class Solution {
public:
    int hammingWeight(int n) {
       //no. of set bits
       int i=0;
       int count=0;
       for(int i=0;i<32;i++){
        if(n &(1<<i)){
            count++;
        }
        else{
            continue;
        }
       } 
       return count;
    }
};