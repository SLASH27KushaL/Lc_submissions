// Last updated: 6/26/2025, 7:56:08 PM
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
       
     int max=nums[0];
    for(int i=0;i<nums.size();i++){
        if(nums[i]>max){
            max=nums[i];
        }

    }   


    vector<int>hash(nums.size()+max,0);

    for(int i=0;i<nums.size();i++){

        hash[nums[i]]++;

    }     

int moves=0;

    for(int i=0;i<hash.size();i++){
        if(hash[i]<=1){
            continue;
        }
        int extras=hash[i]-1;
        moves+=extras;
        hash[i+1]+=extras;
        hash[i]=1;

        
    }
            
        return moves;    
            }
};