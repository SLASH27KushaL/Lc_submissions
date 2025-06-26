// Last updated: 6/26/2025, 7:57:50 PM
#include <vector>
#include <set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> s1(nums.begin(), nums.end()); // Use iterators to initialize the set
        if (nums.size() == s1.size()) { // Compare sizes
            return false; // No duplicates
        }
        return true; // Contains duplicates
    }
};
