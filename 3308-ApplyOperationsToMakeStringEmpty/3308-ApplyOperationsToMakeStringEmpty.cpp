// Last updated: 8/9/2025, 3:05:03 AM
class Solution {
public:
    string lastNonEmptyString(string s) {

 map<char,int>hash;

 for(int i=0;i<s.size();i++){
    hash[s[i]]++;
 }       
 int ans=INT_MIN;
 for(auto it:hash){
    ans=max(ans,it.second);
 }
 //all char having equal to ans will stay
 map<char,int>loc;
 int n=s.size();
 for(int i=0;i<n;i++){
    loc[s[i]]=i;
 }
 string a="";
 priority_queue<pair<int,char>>pq;
 for(auto it:loc){
    if(hash[it.first]==ans){
       pq.push({it.second,it.first});
    }
 } 
 while(!(pq.empty())){
    a+=pq.top().second;
    pq.pop();
 }
reverse(a.begin(),a.end());
 return a;
    }
};