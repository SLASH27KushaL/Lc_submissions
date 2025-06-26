// Last updated: 6/26/2025, 7:57:09 PM
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char, int> hash;

        // Step 1: Count frequency of each character
        for (int i = 0; i < n; i++) {
            hash[s[i]]++;
        }

        // Step 2: Move map data to a vector of pairs
        vector<pair<char, int>> freq(hash.begin(), hash.end());

        sort(freq.begin(), freq.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        string ans = "";
        for (auto& [ch, count] : freq) {
            ans += string(count, ch); 
        }

        return ans;
    }
};
