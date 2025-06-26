// Last updated: 6/26/2025, 7:55:24 PM
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        
        // Calculate the sum of the first k cards from the left
        for (int i = 0; i < k; i++) {
            total += cardPoints[i];
        }
        
        int maxSum = total;
        
        // Slide the window from the end to the start
        for (int i = 0; i < k; i++) {
            total = total - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
            maxSum = max(maxSum, total);
        }
        
        return maxSum;
    }
};
