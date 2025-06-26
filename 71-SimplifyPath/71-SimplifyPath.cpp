// Last updated: 6/26/2025, 7:59:14 PM
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Ignore empty or current directory
                continue;
            } else if (token == "..") {
                // Move up one directory
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                // Valid directory name
                st.push(token);
            }
        }
        
        // Construct the simplified path
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        
        return result.empty() ? "/" : result;
    }
};
