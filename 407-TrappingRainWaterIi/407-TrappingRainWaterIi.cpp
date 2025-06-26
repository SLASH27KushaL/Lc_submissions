// Last updated: 6/26/2025, 7:57:18 PM
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Directions: left, right, down, up
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        if (rows < 3 || cols < 3) return 0;
        int totalUnvisitedCells = rows * cols;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Min-heap: [height, row, col]
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Add boundary cells to the priority queue
        for (int i = 0; i < rows; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][cols - 1], i, cols - 1});
            visited[i][0] = true;
            visited[i][cols - 1] = true;
            totalUnvisitedCells -= 2;
        }
        for (int i = 1; i < cols - 1; i++) {
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[rows - 1][i], rows - 1, i});
            visited[0][i] = true;
            visited[rows - 1][i] = true;
            totalUnvisitedCells -= 2;
        }
        
        int trappedWater = 0;
        int waterLevel = 0;
        
        // Process cells in the priority queue
        while (!pq.empty() && totalUnvisitedCells > 0) {
            vector<int> currentCell = pq.top();
            pq.pop();
            int currentHeight = currentCell[0];
            int currentRow = currentCell[1];
            int currentCol = currentCell[2];
            waterLevel = max(waterLevel, currentHeight);
            
            // Explore all 4 neighboring cells
            for (int direction = 0; direction < 4; direction++) {
                int neighborRow = currentRow + dir[direction][0];
                int neighborCol = currentCol + dir[direction][1];
                
                // Check if the neighbor is within bounds and not visited
                if (isValidCell(neighborRow, neighborCol, rows, cols) && !visited[neighborRow][neighborCol]) {
                    int neighborHeight = heightMap[neighborRow][neighborCol];
                    if (neighborHeight < waterLevel) {
                        trappedWater += waterLevel - neighborHeight;
                    }
                    pq.push({neighborHeight, neighborRow, neighborCol});
                    visited[neighborRow][neighborCol] = true;
                    totalUnvisitedCells--;
                }
            }
        }
        
        return trappedWater;
    }
    
private:
    bool isValidCell(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
};