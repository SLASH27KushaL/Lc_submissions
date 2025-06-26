// Last updated: 6/26/2025, 7:57:27 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies using a hash map
        std::map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }

        
        std::vector<std::pair<int, int>> vec(hash.begin(), hash.end());
        std::sort(vec.begin(), vec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second; 
        });

        std::vector<int> arr;
        for (int i = 0; i < k; i++) {
            arr.push_back(vec[i].first);
        }

        return arr;
    }
};
