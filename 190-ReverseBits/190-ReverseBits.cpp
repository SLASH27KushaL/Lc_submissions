// Last updated: 6/26/2025, 7:58:06 PM
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0; // Initialize the result to 0
        for (int i = 0; i < 32; i++) {
            reversed = (reversed << 1) | (n & 1); // Append the LSB of n to reversed
            n >>= 1; // Shift n right to process the next bit
        }
        return reversed;
    }
};