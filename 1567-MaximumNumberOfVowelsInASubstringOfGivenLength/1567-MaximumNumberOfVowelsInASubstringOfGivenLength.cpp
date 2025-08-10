// Last updated: 8/11/2025, 3:40:56 AM
class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int ans=INT_MIN;
        int count=0;
        int n=s.size();
        while(j<n){
         if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
            count++;
         }
         while(j-i+1>k){
         if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            count--;
         }
         i++;
         }
        ans=max(ans,count);
        j++;         
        }
        return ans;
    }
};