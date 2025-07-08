// Last updated: 7/9/2025, 1:33:16 AM
class Solution {
public:
    // Check if "target" is a subsequence of "s" repeated k times
    bool isSubsequence(const string &s, const string &target, int k) {
        int j = 0;  
        int count = 0; 
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == target[j]) {
                j++;
                if (j == target.size()) {
                    count++;
                    if (count == k) return true;
                    j = 0;  // Start over for next repetition
                }
            }
        }
        return false;
    }

    void backtracking(const string &s, string &curr, vector<bool> &flag, vector<int> &max_use, int k, int maxlen, string &result) {
        if (curr.length() > maxlen) return;

        if ((curr.length() > result.length() || (curr.length() == result.length() && curr > result)) &&
            isSubsequence(s, curr, k)) {
            result = curr;
        }

        for (int i = 0; i < 26; ++i) {
            if (flag[i] && max_use[i] > 0) {
                char ch = 'a' + i;
                curr.push_back(ch);
                max_use[i]--;

                backtracking(s, curr, flag, max_use, k, maxlen, result);

                curr.pop_back();
                max_use[i]++;
            }
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        string result = "";
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<bool> flag(26, false);
        vector<int> max_use(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (freq[i] >= k) {
                flag[i] = true;
                max_use[i] = freq[i] / k;
            }
        }

        int maxlen = n / k;
        string curr = "";
        backtracking(s, curr, flag, max_use, k, maxlen, result);
        return result;
    }
};
