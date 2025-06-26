// Last updated: 6/26/2025, 7:52:53 PM
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int count = 0;
        map<int, int> hash_x_min, hash_x_max;
        map<int, int> hash_y_min, hash_y_max;

        for (const auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            if (hash_x_min.find(x) == hash_x_min.end()) hash_x_min[x] = y;
            else hash_x_min[x] = min(hash_x_min[x], y);

            if (hash_x_max.find(x) == hash_x_max.end()) hash_x_max[x] = y;
            else hash_x_max[x] = max(hash_x_max[x], y);

            if (hash_y_min.find(y) == hash_y_min.end()) hash_y_min[y] = x;
            else hash_y_min[y] = min(hash_y_min[y], x);

            if (hash_y_max.find(y) == hash_y_max.end()) hash_y_max[y] = x;
            else hash_y_max[y] = max(hash_y_max[y], x);
        }

        
        for (const auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            if (x > hash_y_min[y] && x < hash_y_max[y] &&
                y > hash_x_min[x] && y < hash_x_max[x]) {
                count++;
            }
        }

        return count;
    }
};
