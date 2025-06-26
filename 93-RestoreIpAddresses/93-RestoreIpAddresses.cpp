// Last updated: 6/26/2025, 7:58:58 PM
class Solution {
public:
    bool isEligible(const string& s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return false;  
        if (s.size() > 3) return false;                                
        int val = 0;
        for (char c : s) {
            if (!isdigit(c)) return false;                            
            val = val * 10 + (c - '0');
            if (val > 255) return false;                              
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> final;
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    string one = s.substr(0, i + 1);
                    string two = s.substr(i + 1, j - i);
                    string three = s.substr(j + 1, k - j);
                    string four = s.substr(k + 1);

                    if (isEligible(one) && isEligible(two) && isEligible(three) && isEligible(four)) {
                        final.push_back(one + "." + two + "." + three + "." + four);
                    }
                }
            }
        }
        return final;
    }
};
