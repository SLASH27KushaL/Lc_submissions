// Last updated: 7/9/2025, 1:33:39 AM
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>hash;
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        int ans=-1;
        for(auto it:hash){
            if(it.first==it.second){
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};