// Last updated: 8/6/2025, 7:43:32 PM
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;

        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                // Case 1: land first, then water
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStartAfterLand = max(waterStartTime[j], landFinish);
                int waterFinish1 = waterStartAfterLand + waterDuration[j];

                // Case 2: water first, then land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStartAfterWater = max(landStartTime[i], waterFinish);
                int landFinish2 = landStartAfterWater + landDuration[i];

                // Earliest of the two orderings for this pair
                int finishTime = min(waterFinish1, landFinish2);

                minFinishTime = min(minFinishTime, finishTime);
            }
        }

        return minFinishTime;
    }
};