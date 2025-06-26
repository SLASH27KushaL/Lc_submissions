// Last updated: 6/26/2025, 7:56:05 PM
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1; // Single element case

        int left = 0;  // Left boundary of the sliding window
        int max_len = 1;

        for (int right = 1; right < n; right++) {
            int cmp = (arr[right - 1] < arr[right]) ? 1 : (arr[right - 1] > arr[right]) ? -1 : 0;

            if (cmp == 0) {
                left = right;  // Reset window if elements are equal
            } else if (right == 1 || (cmp * ((arr[right - 2] < arr[right - 1]) ? 1 : -1) == -1)) {
                max_len = max(max_len, right - left + 1);
            } else {
                left = right - 1;  // Reset the start of the window
            }
        }

        return max_len;
    }
};
