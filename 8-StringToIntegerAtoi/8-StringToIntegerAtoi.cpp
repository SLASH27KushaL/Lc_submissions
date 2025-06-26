// Last updated: 6/26/2025, 8:00:05 PM
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        while(i < n && s[i] == ' ') i++; // Ignore leading spaces
        
        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        
        long long val = 0;
        while(i < n && isdigit(s[i])){
            val = val * 10 + (s[i] - '0');
            if(val * sign >= INT_MAX) return INT_MAX;
            if(val * sign <= INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(val * sign);
    }
};
