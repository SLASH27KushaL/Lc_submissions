// Last updated: 6/26/2025, 7:59:18 PM
class Solution {
public:
    string addBinary(string a, string b) {
        int one = a.size() - 1;
        int two = b.size() - 1;
        int carry = 0;
        string result;

        while (one >= 0 || two >= 0 || carry) {
            int onee = (one >= 0) ? a[one--] - '0' : 0;
            int twoo = (two >= 0) ? b[two--] - '0' : 0;
            int sum = onee + twoo + carry;
            carry = sum / 2;
            result += (sum % 2) + '0';
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
