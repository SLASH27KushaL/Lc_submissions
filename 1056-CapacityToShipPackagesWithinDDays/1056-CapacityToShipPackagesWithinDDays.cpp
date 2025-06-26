// Last updated: 6/26/2025, 7:55:59 PM
class Solution {
public:
    int calculate(int n, vector<int>& weights) {
        int days = 1; // We need at least one day to ship the items.
        int tt = 0; // Tracks the current weight for the day.
        
        for(int i = 0; i < weights.size(); i++) {
            // If adding the current weight doesn't exceed the capacity, add it to the current day.
            if(tt + weights[i] <= n) {
                tt += weights[i];
            }
            else {
                // Otherwise, start a new day and set tt to the current weight.
                days++;
                tt = weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }

        int low = *max_element(weights.begin(), weights.end());
        int high = sum;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(calculate(mid, weights) > days) {  // We need more days than allowed
                low = mid + 1;  // Increase the max weight per day
            }
            else {  // We can ship within the allowed days
                high = mid - 1;  // Try reducing the max weight per day
            }
        }
        return low;
    }
};
