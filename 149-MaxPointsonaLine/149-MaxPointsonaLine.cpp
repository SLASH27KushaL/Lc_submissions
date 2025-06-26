// Last updated: 6/27/2025, 12:12:37 AM
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 2) return n;
        int ans = 2;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                bool vertical = (dx == 0);
                int count = 2; 
                
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    if (vertical) {
                        if (points[k][0] == points[i][0]) 
                            count++;
                    } else {
                        if ((points[k][1] - points[i][1]) * dx
                            == dy * (points[k][0] - points[i][0]))
                            count++;
                    }
                }
                
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
