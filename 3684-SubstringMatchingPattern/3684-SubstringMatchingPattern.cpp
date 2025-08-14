// Last updated: 8/14/2025, 7:06:22 AM
#include <string>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (m == 0) return true;

        for (int start = 0; start < n; ++start) {
            int i = start;
            int j = 0;

            
            while (i < n && j < m && p[j] != '*' && s[i] == p[j]) {
                ++i; ++j;
            }

            
            if (j == m) return true;

            
            if (j < m && p[j] != '*') continue;

           
            if (j < m && p[j] == '*') {
                ++j; 
                if (j == m) return true;

                
                int sufLen = m - j;
            
                if (sufLen > n) continue; 

                bool matched = false;
              
                for (int pos = i; pos <= n - sufLen; ++pos) {
                   
                    if (s[pos] != p[j]) continue;

                    
                    int k = pos;
                    int t = j;
                    while (k < n && t < m && s[k] == p[t]) { ++k; ++t; }

                    if (t == m) { matched = true; break; } 
                
                }

                if (matched) return true;
                
            }
        }

        return false;
    }
};
