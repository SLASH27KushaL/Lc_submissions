// Last updated: 6/26/2025, 7:53:58 PM
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            int l = s.size();
            if (l % 2 != 0) continue;
            
            int left_half = 0, right_half = 0;
            for (int j = 0; j < l / 2; j++) {
                left_half += s[j] - '0';
            }
            for (int j = l / 2; j < l; j++) {
                right_half += s[j] - '0';
            }
            
            if (left_half == right_half) {
                count++;
            }
        }
        return count;
    }
};
