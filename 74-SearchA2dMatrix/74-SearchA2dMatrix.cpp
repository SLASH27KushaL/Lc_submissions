// Last updated: 6/26/2025, 7:59:10 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int m=matrix[0].size();
        int high=matrix.size()*matrix[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m;
            int column=mid%m;
            if(matrix[row][column]==target){
                return true;
            }
            else if(matrix[row][column]>target){
           high=mid-1;
            }
            else{
           low=mid+1;
            }
        }
        return false;
    }
};