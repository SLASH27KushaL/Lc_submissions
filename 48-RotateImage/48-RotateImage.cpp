// Last updated: 6/26/2025, 7:59:37 PM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
         reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};