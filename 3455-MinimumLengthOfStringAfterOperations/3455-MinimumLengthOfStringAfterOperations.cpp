// Last updated: 6/26/2025, 7:53:37 PM
class Solution {
public:
    int minimumLength(string s) {
        map<char,int>hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        int count=0;
           for (const auto& pair : hash){
          if(pair.second%2==1){
            count+=1;
          }
          else{
            count+=2;
          }
    }
    return count;

    }
};