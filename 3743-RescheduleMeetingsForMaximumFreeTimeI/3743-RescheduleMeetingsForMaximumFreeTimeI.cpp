// Last updated: 7/11/2025, 6:11:24 PM
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;

        gaps.push_back(startTime[0]);

        for (int i = 1; i < n; i++) {
            int gap = startTime[i] - endTime[i - 1];
            gaps.push_back(gap);
        }

        gaps.push_back(eventTime - endTime[n - 1]);

        int sum = 0;
        for (int i = 0; i <= k && i < gaps.size(); i++) {
            sum += gaps[i];
        }

        int ans = sum;

        for (int i = 1; i + k < gaps.size(); i++) {
            sum -= gaps[i - 1];
            sum += gaps[i + k];
            ans = max(ans, sum);
        }

        return ans;
    }
};
