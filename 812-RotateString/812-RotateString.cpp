// Last updated: 6/26/2025, 7:56:30 PM
class Solution {
public:
    bool rotateString(string s, string goal) { 
        if (s.size() != goal.size()) return false;
        goal += goal;
        int len = s.size();
        for (int i = 0; i <= goal.size() - len; i++) {
            string sub(goal.begin() + i, goal.begin() + i + len);
            if (sub == s) {
                return true;
            }
        }
        return false;
    }
};
