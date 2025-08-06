// Last updated: 8/6/2025, 7:44:03 PM
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                st.insert(nums[i]);
            }
        }
        if(st.size()==0){
            return *max_element(nums.begin(),nums.end());
        }
        int s=0;
        for(auto it:st){
            s+=it;
        }
        return s;
    }
};