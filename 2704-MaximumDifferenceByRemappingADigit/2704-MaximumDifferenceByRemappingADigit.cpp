// Last updated: 6/26/2025, 7:54:05 PM
class Solution {
    #define ll long long
public:
    int minMaxDifference(int num) {
        // extract digits of num into a vector
        vector<int> ans;
        ll copy = num;
        if (copy == 0) ans.push_back(0);
        while (copy > 0) {
            ans.push_back(copy % 10);
            copy /= 10;
        }
        reverse(ans.begin(), ans.end());

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

       
        for (int i = 0; i <= 9; i++) {
            ll val9 = 0, val0 = 0;
            for (int d : ans) {
                val9 = val9 * 10 + (d == i ? 9 : d);
                val0 = val0 * 10 + (d == i ? 0 : d);
            }
            maxVal = max(maxVal, val9);
            minVal = min(minVal, val0);
        }

        return int(maxVal - minVal);
    }
};