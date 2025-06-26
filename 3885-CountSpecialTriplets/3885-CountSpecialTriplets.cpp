// Last updated: 6/26/2025, 7:52:29 PM
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long ans = 0;

       
        unordered_map<int,int> rightFreq;
        for (int x : nums) rightFreq[x]++;

        
        unordered_map<int,int> leftFreq;

        for (int j = 0; j < n; ++j) {
            
            rightFreq[nums[j]]--;

            int want = nums[j] * 2;
            long long leftCnt  = leftFreq[want];
            long long rightCnt = rightFreq[want];

           
            ans = (ans + leftCnt * rightCnt) % MOD;

            
            leftFreq[nums[j]]++;
        }

        return (int)ans;
    }
};
