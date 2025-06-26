// Last updated: 6/26/2025, 7:57:06 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter=0;
        vector<int>kus;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 && i<nums.size()-1){
                counter++;

            }
           else if(nums[i]==1 && i==nums.size()-1){
            counter++;
            kus.push_back(counter);
           } 
            else{
             kus.push_back(counter);
                counter=0;
            }
        
        }
   auto max_iter = max_element(kus.begin(), kus.end());
   int max=*max_iter;
    return max;
    
    }
};