// Last updated: 6/26/2025, 7:53:48 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(n * n + 1, 1); 
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[grid[i][j]]--;
            }
        }

        vector<int> final(2);
        for(int i = 1; i <= n * n; i++){ 
            if(ans[i] == 1){
                final[1] = i; 
            }
            else if(ans[i] == -1){
                final[0] = i; 
            }
        }
        return final;
    }
};
