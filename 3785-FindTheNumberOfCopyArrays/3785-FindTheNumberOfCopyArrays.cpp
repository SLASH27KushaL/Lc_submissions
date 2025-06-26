// Last updated: 6/26/2025, 7:53:02 PM
class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int lb = bounds[0][0];  // lower bound for copy[0]
        int ub = bounds[0][1];  // upper bound for copy[0]

        vector<int> sum_dif(n, 0);  // sum_dif[i] = original[i] - original[0]
        for (int i = 1; i < n; ++i) {
            sum_dif[i] = sum_dif[i - 1] + (original[i] - original[i - 1]);
        }

        for (int i = 1; i < n; ++i) {
            int lb_i = bounds[i][0] - sum_dif[i];
            int ub_i = bounds[i][1] - sum_dif[i];

            lb = max(lb, lb_i);
            ub = min(ub, ub_i);
        }

        if (ub < lb) return 0;  // no valid copy[0]
        return ub - lb + 1;     // number of valid integers for copy[0]
    }
};
