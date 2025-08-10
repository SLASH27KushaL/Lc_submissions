// Last updated: 8/11/2025, 3:40:11 AM
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.size();
        string ans="";
        map<int,int>hash;
        for(int i=0;i<spaces.size();i++){
            hash[spaces[i]]++;
        }
        for(int i=0;i<n;i++){
            if(hash[i]){
              ans+=" ";
            }
            ans+=s[i];
        }
        return ans;
        }
};