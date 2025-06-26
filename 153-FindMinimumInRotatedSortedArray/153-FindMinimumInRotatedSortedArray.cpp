// Last updated: 6/26/2025, 7:58:18 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
      int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        

        //if left part is sorted:
        if (nums[low] <= nums[mid]) {
            // keep the minimum:
            ans = min(ans, nums[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, nums[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}
        


 
 };
 