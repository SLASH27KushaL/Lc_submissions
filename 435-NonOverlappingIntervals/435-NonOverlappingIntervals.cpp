// Last updated: 6/26/2025, 7:57:12 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by end time
        });

        int count = 0;
        int prevEnd = intervals[0][1]; // Track the last interval's end time

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) { 
                count++; 
            } else {
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};
