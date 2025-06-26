// Last updated: 6/26/2025, 7:55:04 PM
class Solution {
public:
    bool endsWith(string& str, string& suffix) {
        if (suffix.size() > str.size()) return false;
        return str.substr(str.size() - suffix.size()) == suffix;
    }

    void removeSuffix(string& str, string& suffix) {
        if (str.size() >= suffix.size() && str.substr(str.size() - suffix.size()) == suffix) {
            str.erase(str.size() - suffix.size());
        }
    }

    string removeOccurrences(string s, string part) {
        string ne;
        for (char c : s) {
            ne.push_back(c);
            while (endsWith(ne, part)) {
                removeSuffix(ne, part);
            }
        }
        return ne;
    }
};
