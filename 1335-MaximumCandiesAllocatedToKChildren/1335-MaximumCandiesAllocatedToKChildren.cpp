// Last updated: 6/26/2025, 7:55:42 PM
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        int n = candies.size();
        
        for(int i = 0; i < n; i++){
            sum += candies[i];  // Use long long to prevent overflow
        }

        if (sum < k) return 0; // If we can't even distribute one candy each, return 0

        int l = 1, r = *max_element(candies.begin(), candies.end()); // Upper bound is max candy size
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (canDistribute(candies, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }

    bool canDistribute(vector<int>& nums, long long k, long long per) {
        long long count = 0;
        for (int num : nums) {
            count += num / per; 
        }
        return count >= k;
    }
};
