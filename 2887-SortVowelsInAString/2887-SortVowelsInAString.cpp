// Last updated: 7/15/2025, 4:01:45 PM
class Solution {
public:
    string sortVowels(string s) {
       vector<int>ind;
       int n=s.size();
       vector<char>so;
       for(int i=0;i<s.size();i++){
        if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            ind.push_back(1);
           so.push_back(s[i]);
        }
        else{
            ind.push_back(0);
        }
       }
       //we need to sort places at 1
       sort(so.begin(),so.end());
       string ans="";
       int j=0;
       for(int i=0;i<n;i++){
        if(ind[i]==0){
            ans+=s[i];
        }
        else{
            ans+=so[j];
            j++;
        }
       }
       return ans;
    }
};