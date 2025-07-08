// Last updated: 7/9/2025, 1:32:02 AM
class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        int n = ceil(log2(k)); 
        for (int i = 1; i <= n; i++) {
            string temp = ans;
            for (int j = 0; j < temp.size(); j++){
                temp[j]++;
            }
            ans += temp;
        }
        return ans[k-1];
    }
};
