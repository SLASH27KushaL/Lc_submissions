// Last updated: 6/26/2025, 7:52:32 PM
class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(abs(s)==n){
            return true;
        }
        //case 1
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<n;i++){
            arr1.push_back(nums[i]);
            arr2.push_back(nums[i]);
        }
        int count1=0;
        for(int i=0;i<n-1;i++){
            if(arr1[i]!=1){
                arr1[i]=-1*arr1[i];
                arr1[i+1]=-1*arr1[i+1];
                count1++;
            }
        }
        if(arr1[n-1]!=1){
            count1=INT_MAX;
        }
        int count2=0;
        for(int i=0;i<n-1;i++){
            if(arr2[i]!=-1){
                arr2[i]=-1*arr2[i];
                arr2[i+1]=-1*arr2[i+1];
                count2++;
            }
        }
        if(arr2[n-1]!=-1){
            count2=INT_MAX;
        }

        int ans=min(count1,count2);
        if(ans<=k){
            return true;
        }
        return false;

    }
};