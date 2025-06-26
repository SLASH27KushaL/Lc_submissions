// Last updated: 6/26/2025, 7:59:45 PM
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        recur(candidates, target, 0, cur, res);
        return res;
    }

    void recur(vector<int>& candidates, int target, int ind, vector<int>& cur, vector<vector<int>>& res) {
        // base case
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        
        if (ind == candidates.size()) {
            return;
        }

        // pick
        if (candidates[ind] <= target) {
            cur.push_back(candidates[ind]);
            recur(candidates, target - candidates[ind], ind, cur, res);
            cur.pop_back();
        }
        
        // no pick
        recur(candidates, target, ind + 1, cur, res);
    }
};