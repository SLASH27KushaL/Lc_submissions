// Last updated: 6/26/2025, 7:56:41 PM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); // Initialize result vector with zeros
        stack<pair<int, int>> st; // Stack to store {temperature, index}
        
        for (int i = 0; i < temperatures.size(); i++) {
            // While the stack is not empty and the current temperature is greater
            // than the temperature at the top of the stack
            while (!st.empty() && temperatures[i] > st.top().first) {
                auto [temp, index] = st.top();
                st.pop();
                ans[index] = i - index; // Calculate the days difference
            }
            // Push the current temperature and its index onto the stack
            st.push({temperatures[i], i});
        }
        
        return ans; 
    }
};
