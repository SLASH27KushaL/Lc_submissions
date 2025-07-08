// Last updated: 7/9/2025, 1:31:22 AM
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, int> priority = {
            {"electronics", 1},
            {"grocery", 2},
            {"pharmacy", 3},
            {"restaurant", 4}
        };

        int n = code.size();
        vector<pair<int, string>> validCoupons;

        for (int i = 0; i < n; i++) {
            bool valid = true;
            for (char c : code[i]) {
                if(code[i]==""){
                    valid=false;
                    break;
                }
                if (!isalnum(c) && c != '_') {
                    valid = false;
                    break;
                }
            }

            if (valid && priority.count(businessLine[i]) && isActive[i]) {
                validCoupons.push_back({priority[businessLine[i]], code[i]});
            }
        }

        
        sort(validCoupons.begin(), validCoupons.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        // Extract the sorted codes
        vector<string> result;
        for (auto& p : validCoupons) {
            if(p.second!=""){
            result.push_back(p.second);
        }}

        return result;
    }
};
