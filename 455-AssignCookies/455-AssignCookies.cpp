// Last updated: 6/26/2025, 7:57:07 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         sort(g.begin(),g.end());
         sort(s.begin(),s.end());
         int l=0,r=0;
         int count=0;
         
         while(l<g.size() && r<s.size()){
            if(g[l]<=s[r]){
                l++;
                count++;
            }
            r++;
         }
         return count;
    }
};