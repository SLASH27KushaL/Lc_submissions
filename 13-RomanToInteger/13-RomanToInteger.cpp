// Last updated: 6/26/2025, 8:00:02 PM
class Solution {
public:
    int romanToInt(string s) {

        map<char,int>hash;
        hash.insert({'I',1});
        hash.insert({'V',5});
        hash.insert({'X',10});
        hash.insert({'L',50});
        hash.insert({'C',100});
        hash.insert({'D',500});
        hash.insert({'M',1000});
        int ans=0;
        for(int i=0;i<s.length();i++){
        if(i==s.size()-1){
            ans+=hash[s[i]];
        }
        else if(hash[s[i]]>=hash[s[i+1]]){
            ans+=hash[s[i]];
        }
        else{
            ans-=hash[s[i]];
        }
        }
        return ans;    
        }
};