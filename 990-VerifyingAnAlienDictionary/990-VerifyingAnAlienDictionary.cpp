// Last updated: 7/9/2025, 1:34:03 AM
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> hash;
        for (int i = 0; i < order.size(); i++) {
            hash[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i], &w2 = words[i + 1];
            bool valid = false;
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (hash[w1[j]] < hash[w2[j]]) {
                    valid = true;
                    break;
                } else if (hash[w1[j]] > hash[w2[j]]) {
                    return false;
                }
            }
            if (!valid && w1.size() > w2.size()) {
                return false;
            }
        }
        return true;
    }
};
