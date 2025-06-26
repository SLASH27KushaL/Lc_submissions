// Last updated: 6/26/2025, 7:57:03 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;              
        stack<int> st;                 
        unordered_map<int, int> nextGreaterMap;  

        
        for (int num : nums2) {
          
            while (!st.empty() && st.top() < num){
                nextGreaterMap[st.top()] = num;
                st.pop();                   
            }
            st.push(num);     
        }

    
        for (int num : nums1) {

            if (nextGreaterMap.find(num) != nextGreaterMap.end()) {
                ans.push_back(nextGreaterMap[num]);
            } else {
                ans.push_back(-1); 
            }
        }

        return ans; 
    }
};
