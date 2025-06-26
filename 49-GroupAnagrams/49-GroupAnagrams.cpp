// Last updated: 6/26/2025, 7:59:36 PM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s: strs){
            string original=s;
            sort(s.begin(),s.end());
            mp[s].push_back(original);
        }

        vector<vector<string>>anagrams;
        for(auto [key,vectofstrings]:mp){
            anagrams.push_back(vectofstrings);
        }
        return anagrams;
    }
};