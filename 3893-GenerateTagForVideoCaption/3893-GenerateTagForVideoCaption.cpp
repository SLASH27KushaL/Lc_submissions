// Last updated: 6/26/2025, 7:52:24 PM
class Solution {
public:
    string generateTag(string caption) {
        string ans="#";
        map<int,int>space;
        for(int i=0;i<caption.size();i++){
            if(caption[i]==' ' ){
            space[i]++;
            }
        }
        for(int i=0;i<caption.size();i++){
         
            if(space[i]==1){
      if(caption[i+1]>=97 && caption[i+1]<=122 && i>0){
        caption[i+1]-=32;
      }
      else{
        if(caption[i]>='A' && caption[i]<='Z'){
            caption[i]+=32;
        }
      }}
      else
      {
        if(caption[i]>='A' && caption[i]<='Z' && space[i-1]==0 && i>=1){
            caption[i]+=32;
        }
      }
    
    if(space[i]==0 && ans.size()<100){
        ans+=caption[i];
    }    
   }
   if(ans[1]>='A' && ans[1]<='Z'){
    ans[1]+=32;
   }
        return ans;
    }
};