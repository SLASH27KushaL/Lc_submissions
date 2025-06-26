// Last updated: 6/26/2025, 7:57:40 PM
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>hash1;
        map<char,int>hash2;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            hash1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            hash2[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(hash1[s[i]]==hash2[s[i]]){
                continue;
            }
            else{
                return false;
            }

        }
        return true;
    }
};