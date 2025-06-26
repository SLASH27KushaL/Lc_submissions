// Last updated: 6/26/2025, 7:54:46 PM
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int, int> hash;
        for (int digit : digits) {
            hash[digit]++;
        }

        vector<int> ans;

        // hundreds digit (i): must be from 1 to 9 (no leading 0)
        for (int i = 1; i <= 9; i++) {
            if (hash[i] == 0) continue;
            hash[i]--;

            // tens digit (j): can be 0 to 9
            for (int j = 0; j <= 9; j++) {
                if (hash[j] == 0) continue;
                hash[j]--;

                // units digit (k): must be even and from 0 to 8
                for (int k = 0; k <= 8; k += 2) {
                    if (hash[k] == 0) continue;

                    int num = i * 100 + j * 10 + k;
                    ans.push_back(num);
                }

                hash[j]++;
            }

            hash[i]++;
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};
