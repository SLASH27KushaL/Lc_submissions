// Last updated: 7/9/2025, 1:33:23 AM
class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> hash1, hash2;

public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;

        for (int x : nums1) {
            hash1[x]++;
        }

        for (int x : nums2) {
            hash2[x]++;
        }
    }

    void add(int index, int val) {
        int old_val = nums2[index];
        int new_val = old_val + val;

        hash2[old_val]--;
        if (hash2[old_val] == 0) {
            hash2.erase(old_val);
        }

        nums2[index] = new_val;
        hash2[new_val]++;
    }

    int count(int tot) {
        int c = 0;
        for (const auto& [num, freq1] : hash1) {
            int target = tot - num;
            if (hash2.count(target)) {
                c += freq1 * hash2[target];
            }
        }
        return c;
    }
};
