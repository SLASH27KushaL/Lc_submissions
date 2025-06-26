// Last updated: 6/26/2025, 7:55:25 PM
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int flag1=0;
        int flag2=0;
        int n=s1.size();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int i=0;int j=0;
        while(i<n && j<n){
            if(s2[j]>=s1[i]){
                i++;

            }
            j++;
        }
        if(i<n){
       flag1=1;
   }


   //check for s2
     i=0; j=0;
        while(i<n && j<n){
            if(s1[j]>=s2[i]){
                i++;
            }
            j++;
        }
        if(i<n){
     flag2=1;
   }
   if(flag1==1 && flag2==1){
    return false;
   }
   return true;
    }
};