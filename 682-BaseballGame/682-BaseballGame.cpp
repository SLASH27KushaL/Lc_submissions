// Last updated: 6/26/2025, 7:56:47 PM
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                if (s.size() >= 2) {
                    int top1 = s.top(); s.pop();
                    int top2 = s.top();
                    s.push(top1); // Push back the first top element
                    s.push(top1 + top2); // Push the sum
                }
            } else if (operations[i] == "D") {
                if (!s.empty()) {
                    s.push(2 * s.top());
                }
            } else if (operations[i] == "C") {
                if (!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(stoi(operations[i]));
            }
        }
        
        int ans = 0;
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};
