// Last updated: 6/26/2025, 7:54:24 PM
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<long long, long long> hash;
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2; 
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            long long key = nums[i] - i;  
            goodPairs += hash[key];  
            hash[key]++;  
        }

        return totalPairs - goodPairs;  
    }
};
