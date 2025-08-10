// Last updated: 8/11/2025, 3:40:50 AM
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int,int> hash;
        int ans = 0, sum = 0;
        
        while (j < n) {
           
            hash[nums[j]]++;
            sum += nums[j];
            
           
            while (hash[nums[j]] > 1) {
                hash[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            ans = max(ans, sum);
            j++;
        }
        
        return ans;
    }
};
