// Last updated: 6/26/2025, 7:54:40 PM
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
    vector<string>ans;
       string temp="";
       for(int i=0;i<n;i++){
        if(temp.size()<k){
        temp+=s[i];
        }
        else{
            ans.push_back(temp);
            temp=s[i];
        }
       }
       ans.push_back(temp);
       if(n%k!=0){
     int m=ans.size();
     
        while(ans[m-1].size()!=k){
            ans[m-1]+=fill;
        }
       }
       return ans; 
    }
};