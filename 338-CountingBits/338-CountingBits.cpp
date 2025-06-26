// Last updated: 6/26/2025, 7:57:32 PM
class Solution {
public:
int setone(int x){
    int count=0;
    for(int i=0;i<32;i++){
        if(x &(1<<i)){
            count++;
        }
        else{
            continue;
        }
    }
    return count;
}
public:
    vector<int> countBits(int n){
    vector<int>ans;
      for(int i=0;i<=n;i++){
      ans.push_back(setone(i));
      }  
return ans;
    }
    
};