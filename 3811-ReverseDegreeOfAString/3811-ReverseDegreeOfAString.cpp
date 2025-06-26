// Last updated: 6/26/2025, 7:52:57 PM
class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
       sum+=(i+1)*(26-(s[i]-'a'));
        }
        return sum;
    }
};