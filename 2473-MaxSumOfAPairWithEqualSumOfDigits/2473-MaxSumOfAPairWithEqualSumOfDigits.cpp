// Last updated: 6/26/2025, 7:54:21 PM
class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> hash;
        
        for (int num : nums) {
            int sum = sumOfDigits(num);
            hash[sum].push_back(num);
        }

        int maxi_sum = -1;

        for (const auto& pair : hash) {
            const vector<int>& v = pair.second;
            
            if (v.size() >= 2) {
                vector<int> temp = v; 
                sort(temp.rbegin(), temp.rend()); 
                
                int sum = temp[0] + temp[1];
                maxi_sum = max(maxi_sum, sum);
            }
        }
        return maxi_sum;
    }
};