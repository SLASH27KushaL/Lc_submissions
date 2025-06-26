// Last updated: 6/26/2025, 7:53:42 PM
class Solution {
public:
    string triangleType(vector<int>& nums) {
    map<int,int>hash;
        for(int i=0;i<nums.size();i++){
           hash[nums[i]]++;
        }
        //sum of any two sides should be greater than third therefor make 3 combinaions 
        if(nums[0]+nums[1]>nums[2] && nums[1]+nums[2]>nums[0] && nums[0]+nums[2]>nums[1]){
         if(hash.size()==1){
          string  s="equilateral";
            return s;
        }
        else if(hash.size()==2){
            string s="isosceles";
            return s;
        }
        else{
            string s="scalene";
            return s;
        }
        }
        return "none";
    }
};