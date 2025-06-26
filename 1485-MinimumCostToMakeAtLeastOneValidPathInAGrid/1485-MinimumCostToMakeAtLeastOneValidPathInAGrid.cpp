// Last updated: 6/26/2025, 7:55:31 PM
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> minCost(rows, vector<int>(cols, INT_MAX));

        // Directions: right, left, down, up
        vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

        // Min-heap: elements [cost, row, col], sorted by cost (ascending)
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        // Insert the first element
        pq.push({0, 0, 0}); // cost, row, col
        minCost[0][0] = 0; // Cost from source to source

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int cost = curr[0], row = curr[1], col = curr[2];

            // Explore only if cost is less than minCost
            if (minCost[row][col] < cost) continue;

            for (int dir = 0; dir < 4; dir++) {
                int nextRow = row + dirs[dir][0];
                int nextCol = col + dirs[dir][1];

                // Check if new position is valid
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols) {
                    // If direction is changed, cost will be 1
                    int nextCellCost = (dir + 1 == grid[row][col]) ? 0 : 1;
                    int newCost = cost + nextCellCost;

                    if (newCost < minCost[nextRow][nextCol]) {
                        minCost[nextRow][nextCol] = newCost;
                        pq.push({newCost, nextRow, nextCol});
                    }
                }
            }
        }

        return minCost[rows - 1][cols - 1];
    }
};