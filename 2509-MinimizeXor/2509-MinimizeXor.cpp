// Last updated: 6/26/2025, 7:54:18 PM
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Find the number of set bits in num2
        int setBits = __builtin_popcount(num2); 
        int bit = 31;
        int res = 0;

        // Set bits in result where num1 already has bits set
        while (bit >= 0 && setBits > 0){
            if ((num1 & (1 << bit)) != 0) {
                res |= (1 << bit);
                setBits--;
            }
            bit--;
        }

        bit = 0;

        // Set remaining bits in result where num1 has no bits set
        while (setBits > 0 && bit <= 32) {
            if ((num1 & (1 << bit)) == 0) {
                res |= (1 << bit);
                setBits--;
            }
            bit++;
        }

        return res;
    }
};
