// Last updated: 6/26/2025, 7:55:06 PM
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       return findxor(nums,0,0);
    }
    int findxor(vector<int>& arr,int index,int xoor){
        if(index==arr.size()){
            return xoor;
        }
        int pick=findxor(arr,index+1,xoor^arr[index]);
        int nopick=findxor(arr,index+1,xoor);
        return pick+nopick;
    }
};