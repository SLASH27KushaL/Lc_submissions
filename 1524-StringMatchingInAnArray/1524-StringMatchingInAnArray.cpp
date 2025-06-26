// Last updated: 6/26/2025, 7:55:28 PM
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break; 
                }
            }
        }
        return ans;
    }
};
