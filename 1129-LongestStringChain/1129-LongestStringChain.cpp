// Last updated: 6/26/2025, 7:55:53 PM
class Solution {
public:
    bool poss(string s1, string s2) {
        if (s1.size() != s2.size() + 1) return false;
        int i = 0, j = 0;
        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++; j++;
            } else {
                i++;
            }
        }
        return (i == s1.size() && j == s2.size());
    }

    int f(int ind, int prev, vector<string>& words, vector<vector<int>>& dp) {
        if (ind == words.size()) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int take = 0;
        if (prev == -1 || poss(words[ind], words[prev])) {
            take = 1 + f(ind + 1, ind, words, dp);
        }

        int skip = f(ind + 1, prev, words, dp);

        return dp[ind][prev + 1] = max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, words, dp);
    }
};
