// Last updated: 8/11/2025, 3:40:41 AM
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>hash;
        for(int i=0;i<edges.size();i++){
        hash[edges[i][1]]++;
        }
        int ans=INT_MIN;
        int res=0;
        for(auto it:hash){
            int prev=ans;
            ans=max(ans,it.second);
            if(ans!=prev){
                res=it.first;
            }
        }
        return res;
    }
};