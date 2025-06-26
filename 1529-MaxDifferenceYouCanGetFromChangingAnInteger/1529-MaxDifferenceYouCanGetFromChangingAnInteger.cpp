// Last updated: 6/26/2025, 7:55:27 PM
class Solution {
public:
    int maxDiff(int num) {
        // extract digits
        vector<int> arr;
        int copy = num;
        if (copy == 0) arr.push_back(0);
        while (copy > 0) {
            arr.push_back(copy % 10);
            copy /= 10;
        }
        reverse(arr.begin(), arr.end());
        int n = arr.size();
        
        
        long long bound = 1;
        for (int i = 1; i < n; ++i) bound *= 10;
        
        long long mini = num, maxi = num;
        
        for (int x = 0; x <= 9; ++x) {
            for (int y = 0; y <= 9; ++y) {
                if (x == y) continue;
                long long val = 0;
                for (int j = 0; j < n; ++j) {
                    int d = (arr[j] == x ? y : arr[j]);
                    val = val * 10 + d;
                }
                
                if (val >= bound) {
                    maxi = max(maxi, val);
                }
            }
        }
        
        for (int x = 0; x <= 9; ++x) {
            for (int y = 0; y <= 9; ++y) {
                if (x == y) continue;
                long long val = 0;
                for (int j = 0; j < n; ++j) {
                    int d = (arr[j] == x ? y : arr[j]);
                    val = val * 10 + d;
                }
                
                if (val >= bound) {
                    mini = min(mini, val);
                }
            }
        }
        
        return int(maxi - mini);
    }
};
