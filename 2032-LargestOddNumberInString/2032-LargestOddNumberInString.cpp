// Last updated: 6/26/2025, 7:55:03 PM
class Solution {
public:
    string largestOddNumber(string num) {
        int indi=-1;
        for(int i=0;i<num.size();i++){
          int val=num[i]-'0';
          if(val&1){
            indi=i;
          }
        }
        string ans="";
        if(indi==-1){
            return ans;
        }
        for(int i=0;i<=indi;i++){
            ans+=num[i];
        }
        return ans;
    }
};