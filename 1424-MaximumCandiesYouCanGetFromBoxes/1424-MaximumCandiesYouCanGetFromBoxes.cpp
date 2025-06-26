// Last updated: 6/26/2025, 7:55:37 PM
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        queue<int> q;
        vector<bool> hasKey(n, false);
        vector<bool> hasBox(n, false);
        vector<bool> visited(n, false);

        for (int box : initialBoxes) {
            hasBox[box] = true;
            q.push(box);
        }

        int count = 0;

        while (!q.empty()) {
            int b = q.front(); q.pop();

            if (visited[b]) continue;

            if (!status[b] && !hasKey[b]) continue;

            visited[b] = true;
            count += candies[b];

            for (int k : keys[b]) {
                if (!hasKey[k]) {
                    hasKey[k] = true;
                    if (hasBox[k] && !visited[k]) {
                        q.push(k);
                    }
                }
            }

            for (int c : containedBoxes[b]) {
                if (!hasBox[c]) {
                    hasBox[c] = true;
                }
                if (!visited[c]) {
                    q.push(c);
                }
            }
        }

        return count;
    }
};
