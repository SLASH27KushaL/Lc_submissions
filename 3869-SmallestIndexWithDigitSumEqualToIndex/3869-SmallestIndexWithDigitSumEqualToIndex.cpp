// Last updated: 6/26/2025, 7:52:36 PM
class Solution {
public:
    int digit(int m) {
        int s = 0;
        while (m > 0) {
            s += m % 10;
            m /= 10;
        }
        return s;
    }
    int mini=INT_MAX;
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (digit(nums[i]) == i) {
                mini=min(mini,digit(nums[i]));
                
            }
        }
        if(mini!=INT_MAX){
return mini;}
        return -1;  
    }
};
