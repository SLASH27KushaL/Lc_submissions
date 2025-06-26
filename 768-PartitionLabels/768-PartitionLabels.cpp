// Last updated: 6/26/2025, 7:56:37 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> lastIndex; 
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;         }

        vector<int> ans;
        int size = 0, end = 0; 

        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i]]);  
            size++;

            if (i == end) { 
                ans.push_back(size);
                size = 0;  
            }
        }
        return ans;
    }
};
