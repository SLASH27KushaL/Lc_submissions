// Last updated: 6/26/2025, 7:56:26 PM
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < position.size(); i++) {
            arr.push_back({position[i], speed[i]});
        }
        
        // Sort by position in descending order
        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        
        stack<float> s;
        for (const auto& it : arr) {
            // Calculate time to reach the target
            float time = (float)(target - it.first) / it.second;
            // Check if this car forms a new fleet
            if (!s.empty() && s.top() >= time) {
                continue;
            }
            s.push(time);
        }
        
        return s.size();
    }
};
