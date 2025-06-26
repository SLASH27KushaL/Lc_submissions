// Last updated: 6/26/2025, 7:57:26 PM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>flag;
        map<int,int>hash1;
        map<int,int>hash2;
        for(int i=0;i<nums1.size();i++){
         hash1[nums1[i]]++;
        
         }
        for(int i=0;i<nums2.size();i++){
            hash2[nums2[i]]++;
           
        }
        vector<int>ans;
        if(nums1.size()>=nums2.size()){
            for(int i=0;i<nums1.size();i++){
                if((hash1[nums1[i]]>=1) && (hash2[nums1[i]]>=1)){
                    if(flag[nums1[i]]==0){
                        ans.push_back(nums1[i]);
                        flag[nums1[i]]++;
                    }

                }
            }

        }
        else{
            for(int i=0;i<nums2.size();i++){
                if((hash1[nums2[i]]>=1) && (hash2[nums2[i]]>=1)){
                    if(flag[nums2[i]]==0){
                        ans.push_back(nums2[i]);
                        flag[nums2[i]]++;
                    }
                }
            }
        }
        return ans;
    }
};