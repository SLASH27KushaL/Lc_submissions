// Last updated: 6/26/2025, 7:57:19 PM
class Solution {
public:
    string decodeString(const string& s) {
        stack<string> strStack;
        stack<int> numStack;
        string currentStr = "";
        int currentNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                // Build the number
                currentNum = currentNum * 10 + (ch - '0');
            } else if (ch == '[') {
                // Push current number and string onto stacks
                numStack.push(currentNum);
                strStack.push(currentStr);
                // Reset for new context
                currentNum = 0;
                currentStr = "";
            } else if (ch == ']') {
                // Decode the string
                int repeatCount = numStack.top(); numStack.pop();
                string previousStr = strStack.top(); strStack.pop();

                string decoded = "";
                for (int i = 0; i < repeatCount; ++i) {
                    decoded += currentStr;
                }
                currentStr = previousStr + decoded;
            } else {
                // Accumulate characters
                currentStr += ch;
            }
        }
        return currentStr;
    }
};
