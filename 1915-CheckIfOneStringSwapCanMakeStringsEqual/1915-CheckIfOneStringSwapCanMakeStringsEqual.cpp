// Last updated: 6/26/2025, 7:55:10 PM
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char, int> hash1, hash2;
        
        for (char c : s1) hash1[c]++;
        for (char c : s2) hash2[c]++;
        
        if (hash1 != hash2) return false;
        vector<int> diffIndices;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
                if (diffIndices.size() > 2) return false; 
            }
        }
        if (diffIndices.empty()) return true;
        return (diffIndices.size() == 2 &&
                s1[diffIndices[0]] == s2[diffIndices[1]] &&
                s1[diffIndices[1]] == s2[diffIndices[0]]);
    }
};
