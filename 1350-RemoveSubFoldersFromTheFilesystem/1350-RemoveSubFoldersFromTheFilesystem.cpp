// Last updated: 8/11/2025, 3:41:08 AM
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder){        
        sort(folder.begin(),folder.end());
        int n=folder.size();
        vector<string>ans;
        map<string,int>hash;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<folder[i].size();j++)
{
    temp+=folder[i][j];
 if(hash[temp]==1 && folder[i][j+1]=='/'){
     break;
 }
 else{
    if(j==folder[i].size()-1)
    {
        hash[temp]++;
       ans.push_back(temp);
    }
 }


}        
}
return ans;
    }
};