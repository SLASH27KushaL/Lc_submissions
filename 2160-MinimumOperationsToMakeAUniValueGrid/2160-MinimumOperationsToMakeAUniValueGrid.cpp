// Last updated: 6/26/2025, 7:54:52 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int result=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int midi=arr[(arr.size()-1)/2];
        int count=0;
        for(int i=0;i<arr.size();i++){
         if(arr[i]%x!=midi%x){
            return -1;
            break;
         }
         else{
            count+=abs(arr[i]-midi)/x;
         }
        }
        return count;
    }
};