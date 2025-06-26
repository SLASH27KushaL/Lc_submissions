// Last updated: 6/26/2025, 7:55:36 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
   vector<int>last_seen(3,-1);
   int count=0;
   for(int i=0;i<s.size();i++){
    last_seen[s[i]-'a']=i;
    if(s[0]!=-1 && s[1]!=-1 && s[2]!=-1){
    count+=1+min({last_seen[0],last_seen[1],last_seen[2]});
   }}
   return count;
}
};