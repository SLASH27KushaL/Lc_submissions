// Last updated: 6/26/2025, 7:55:51 PM
class Solution {

public:
    string gcdOfStrings(string str1, string str2) {
        // Check if str1 + str2 == str2 + str1
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Calculate the GCD of the lengths of the two strings
        int len1 = str1.size();
        int len2 = str2.size();
        int gcdLength = gcd(len1, len2);

        // Return the substring from 0 to gcdLength as the GCD string
        return str1.substr(0, gcdLength);
    }

private:
    // Helper function to compute the GCD of two numbers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
