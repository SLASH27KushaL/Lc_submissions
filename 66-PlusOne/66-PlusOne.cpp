// Last updated: 6/26/2025, 7:59:20 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1; // Start with carry as 1 since we are adding 1

        // Process digits from right to left
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry; // Add the current digit and carry
            ans.push_back(sum % 10);  
            carry = sum / 10;         
        }

        if (carry > 0) {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
