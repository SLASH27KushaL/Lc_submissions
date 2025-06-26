// Last updated: 6/26/2025, 7:53:06 PM
class Solution {
public:
    int maxDifference(string s) {
        vector<int>odd;
        vector<int>even;
        map<char,int>hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        for(auto [ch,count]:hash){
            if(count&1){
             odd.push_back(count);
            }
            else{
            even.push_back(count);
            }
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.begin(),even.end());
        return odd[0]-even[0];
    }
};