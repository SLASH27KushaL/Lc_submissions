// Last updated: 6/26/2025, 7:57:25 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1); 
    vector<int> hash(n, -1);

    for (int i = 0; i < n; i++) {
        hash[i] = i; 
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
    }
};