// Last updated: 6/26/2025, 7:55:43 PM
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=2;i<arr.size();i++){
            if((arr[i-2]&1) && (arr[i-1]&1) && (arr[i]&1)){
                return true;
            }
        }

        return false;
    }
};