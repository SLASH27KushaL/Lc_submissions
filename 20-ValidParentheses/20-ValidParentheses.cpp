// Last updated: 6/26/2025, 7:59:57 PM
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.empty()) {
                    return false;
                }
                char top = st.top();
                if((s[i] == ')' && top == '(') ||
                   (s[i] == ']' && top == '[') ||
                   (s[i] == '}' && top == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

