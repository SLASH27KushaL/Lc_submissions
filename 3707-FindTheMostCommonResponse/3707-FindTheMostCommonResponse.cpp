// Last updated: 6/26/2025, 7:53:11 PM
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> hash;
        
        for (int i = 0; i < responses.size(); i++) {
            set<string> st;
            for (int j = 0; j < responses[i].size(); j++) {
                st.insert(responses[i][j]);
            }
            for (auto it = st.begin(); it != st.end(); ++it) {
                hash[*it]++;
            }
        }

        string ans = "";
        int maxi = INT_MIN;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            if (it->second > maxi) {
                maxi = it->second;
                ans = it->first;
            }
        }

        return ans;
    }
};
