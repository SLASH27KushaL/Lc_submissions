// Last updated: 6/26/2025, 7:54:20 PM
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int count = 0;
        int xorr = 0;

        while (r < n) {  
            while ((xorr & nums[r]) != 0) {  
                xorr ^= nums[l];  
                l++;
            }
            xorr |= nums[r]; 
            count = max(count, r - l + 1);
            r++;  
        }

        return count;
    }
};
