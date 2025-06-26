// Last updated: 6/26/2025, 7:59:41 PM
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; 

        vector<int> ans(num1.size() + num2.size(), 0);

        for (int i = num2.size() - 1; i >= 0; i--) {
            for (int j = num1.size() - 1; j >= 0; j--) {
                int product = (num2[i] - '0') * (num1[j] - '0');
                int sum = ans[i + j + 1] + product; 
                ans[i + j + 1] = sum % 10;          
                ans[i + j] += sum / 10;             
            }
        }

        string res;
        for (int digit : ans) {
            if (!(res.empty() && digit == 0)) { 
                res.push_back(digit + '0');
            }
        }

        return res;
    }
};
