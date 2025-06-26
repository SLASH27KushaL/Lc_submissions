// Last updated: 6/26/2025, 7:53:16 PM
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int m = numFriends;

        
        if (m == 1) {
            return word;
        }

        int rem = n - m;
        if (rem == 0) {
            char best = word[0];
            for (char c : word) {
                if (c > best) best = c;
            }
            return string(1, best);
        }

        int ans = 0;
        for (int l = 0; l < n; l++) {
            if (word[l] == word[ans]) {
               
                int i = 0;
                int count = 1;
                while (l + i < n &&
                       ans + i < n &&
                       word[l + i] == word[ans + i] &&
                       count <= rem) {
                    i++;
                    count++;
                }
                if (l + i < n && ans + i < n &&
                    word[l + i] > word[ans + i]) {
                    ans = l;
                }
            }
            else if (word[l] > word[ans]) {
                
                int maxRemAtL = (n - 1) - l;
                if (maxRemAtL >= rem) {
                   
                    ans = l;
                } else {
                    rem = maxRemAtL;
                    ans = l;
                }
            }
            else {
                continue;
            }
        }

       
        string s;
        for (int i = ans; i < ans + rem + 1 && i < n; i++) {
            s += word[i];
        }
        return s;
    }
};

