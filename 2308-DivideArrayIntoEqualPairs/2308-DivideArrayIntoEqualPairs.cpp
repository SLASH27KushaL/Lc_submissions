// Last updated: 6/26/2025, 7:54:33 PM


class Solution {
public:
    bool divideArray(vector<int>& nums) {
            map<int, int> hash;
                    
                            // Count frequency of each number
                                    for (int num : nums) {
                                                hash[num]++;
                                                        }
                                                                
                                                                        // Check if all frequencies are even
                                                                                for (auto it : hash) {
                                                                                            if (it.second % 2 != 0) {
                                                                                                            return false;
                                                                                                                        }
                                                                                                                                }
                                                                                                                                        
                                                                                                                                                return true;
                                                                                                                                                    }
                                                                                                                                                    };