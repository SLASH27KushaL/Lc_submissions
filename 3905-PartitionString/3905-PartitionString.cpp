// Last updated: 6/29/2025, 11:44:13 PM
class Solution {
public:
    vector<string> partitionString(string s) {
       map<string,int>hash;
      
       vector<string>ans;
       string sub="";
       for(int i=0;i<s.size();i++){
        sub+=s[i];
        if(hash[sub]==0){
        hash[sub]++;
        ans.push_back(sub);
        sub="";
        }
        else{
          continue;
        }
       }
       return ans;
    }
};