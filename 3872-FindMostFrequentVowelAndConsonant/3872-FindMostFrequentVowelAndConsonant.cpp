// Last updated: 6/26/2025, 7:52:33 PM
class Solution {
public:
    int maxFreqSum(string s) {
     map<char,int>hash1;
     map<char,int>hash2;
     for(int i=0;i<s.size();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            hash1[s[i]]++;
        }
        else{
            hash2[s[i]]++;
        }
     }   
     int maxi1=0;int maxi2=0;
         for (auto it : hash1) {
        maxi1=max(maxi1,it.second);
    }

    
    for (auto it : hash2) {
        maxi2=max(maxi2,it.second);
    }
    return maxi1+maxi2;
    }
};