// Last updated: 6/26/2025, 7:56:22 PM
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxLen = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prev = arr[i];
                int curr = arr[j]; // Fix: `curr` should start at arr[j], not arr[i] + arr[j]
                int len = 2;

                while (numSet.find(prev + curr) != numSet.end()) {
                    int temp = curr;
                    curr = prev + curr;
                    prev = temp;
                    maxLen = max(maxLen, ++len);
                }
            }
        }
        return maxLen >= 3 ? maxLen : 0; 
    }
};
