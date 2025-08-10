// Last updated: 8/11/2025, 3:40:38 AM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0, j = 0;
        long long windowSum = 0;
        int maxFreq = 0;
        
        while (j < n) {
           
            windowSum += nums[j];
            
           
            while ((long long)nums[j] * (j - i + 1) - windowSum > k) {
                windowSum -= nums[i];
                ++i;
            }
            
            maxFreq = max(maxFreq, j - i + 1);
            
            ++j;
        }
        
        return maxFreq;
    }
};
