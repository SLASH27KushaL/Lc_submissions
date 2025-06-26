// Last updated: 6/26/2025, 7:59:05 PM
class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        poss(n, arr, k);
        return ans;
    }
    
    void poss(int i, vector<int>& arr, int k) {
        if (arr.size() == k) {
            ans.push_back(arr);
            return;
        }
        if (i < 1) { 
            return;
        }

        arr.push_back(i);
        poss(i - 1, arr, k);
        arr.pop_back(); 

        poss(i - 1, arr, k);
    }
};
