// Last updated: 6/26/2025, 7:57:20 PM
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;

        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            if (current * 10 <= n) {
                current *= 10;
            } else {
                while (current % 10 == 9 || current + 1 > n) {
                    current /= 10;  
                }
                ++current;  
            }
        }

        return result;
    }
};
