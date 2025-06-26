// Last updated: 6/26/2025, 7:53:55 PM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        ans.push_back(words[0]);
        int group=groups[0];
        for(int i=1;i<groups.size();i++){
            if(groups[i]!=group){
                ans.push_back(words[i]);
               group=groups[i];
            }
        }
        return ans;
    }
};