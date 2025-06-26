// Last updated: 6/26/2025, 7:53:00 PM
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        sort(digits.begin(), digits.end());
        
        vector<int> store;
        for (int idx = 0; idx < n; idx++) {
            if ((digits[idx] & 1) == 0) {
                store.push_back(idx);
            }
        }
        
        set<int> st;
        for (int p = 0; p < store.size(); p++) {
            int lastIdx = store[p];
            int last = digits[lastIdx];
            for (int j = 0; j < n; j++) {
                if (j == lastIdx) continue;
                int mid = digits[j];
                for (int k = 0; k < n; k++) {
                    if (k == lastIdx || k == j) continue;
                    int first = digits[k];
                    if (first == 0) continue; 
                    int num = first * 100 + mid * 10 + last;
                    st.insert(num);
                }
            }
        }
        
        return st.size();
    }
};
