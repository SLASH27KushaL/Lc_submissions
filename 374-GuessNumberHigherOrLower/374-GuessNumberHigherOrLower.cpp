// Last updated: 6/26/2025, 7:57:22 PM
class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid overflow
            int result = guess(mid);
            if (result == 0) {
                return mid; // Found the correct number
            } else if (result == -1) {
                right = mid - 1; // Picked number is lower
            } else {
                left = mid + 1; // Picked number is higher
            }
        }
        return -1; // Should never reach here
    }
};