// Last updated: 6/26/2025, 7:53:38 PM
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>> arr(26);
        set<int> active;            
        vector<int> banned(n, 0);

        
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                int ch = s[i] - 'a';
                arr[ch].push(i);
                if (arr[ch].size() == 1) {
                    active.insert(ch);
                }
            }
            else if (s[i] == '*') {
                if (!active.empty()) {
                    int smallest = *active.begin();        
                    int idx = arr[smallest].top();
                    arr[smallest].pop();
                    banned[idx] = 1;
                    if (arr[smallest].empty()) {
                        active.erase(smallest);
                    }
                }
            }
        }

        string result;
        result.reserve(n);
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !banned[i]) {
                result += s[i];
            }
        }
        return result;
    }
};
