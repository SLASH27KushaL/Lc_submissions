// Last updated: 6/26/2025, 7:54:45 PM
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false; // A valid string must have even length
        
        // Forward pass
        int open = 0; // Tracks possible '(' count
        int balance = 0; // Tracks overall balance
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (locked[i] == '0' || ch == '(') {
                open++;
            } else {
                open--;
            }
            balance += (locked[i] == '0' ? 1 : (ch == '(' ? 1 : -1));
            if (balance < 0) return false; // Too many unmatched ')'
        }
        
        if (open < 0) return false; // Not enough '(' to balance
        
        // Backward pass
        open = 0;
        balance = 0;
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            if (locked[i] == '0' || ch == ')') {
                open++;
            } else {
                open--;
            }
            balance += (locked[i] == '0' ? 1 : (ch == ')' ? 1 : -1));
            if (balance < 0) return false; // Too many unmatched '('
        }
        
        return open >= 0; // Ensure all are balanced
    }
};
