// Last updated: 6/26/2025, 7:56:49 PM
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Find the index of x or the closest element to x
        int ind = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                ind = i;
                break;
            }
        }
        
        // If x is not in the array, find the closest index using binary search
        if (ind == -1) {
            ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            if (ind > 0 && (ind == arr.size() || abs(arr[ind - 1] - x) <= abs(arr[ind] - x))) {
                ind--;
            }
        }

        // Initialize two pointers around the closest index
        int l = ind - 1;
        int r = ind + 1;
        vector<int> ans = {arr[ind]}; // Start with the closest element

        // Expand the range to find the k closest elements
        while (ans.size() < k) {
            if (l >= 0 && r < arr.size()) {
                if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                    ans.push_back(arr[l--]);
                } else {
                    ans.push_back(arr[r++]);
                }
            } else if (l >= 0) {
                ans.push_back(arr[l--]);
            } else if (r < arr.size()) {
                ans.push_back(arr[r++]);
            }
        }

        // Sort the result before returning
        sort(ans.begin(), ans.end());
        return ans;
    }
};
