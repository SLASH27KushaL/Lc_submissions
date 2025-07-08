// Last updated: 7/9/2025, 1:34:06 AM
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, insertions = 0;
        for (char c : s) {
            if (c == '(') {
                open++;  
            } else {  
                if (open > 0) {
                    open--;  
                } else {
                    insertions++; 
                }
            }
        }
        return insertions + open;  
    }
};
