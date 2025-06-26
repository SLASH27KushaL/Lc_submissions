// Last updated: 6/26/2025, 7:58:11 PM
class Solution {
public:
    string convertToTitle(int columnNumber){
        string ans;
        while (columnNumber > 0) {
            columnNumber--;
            int n = columnNumber % 26;
            ans += ('A' + n); 
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
