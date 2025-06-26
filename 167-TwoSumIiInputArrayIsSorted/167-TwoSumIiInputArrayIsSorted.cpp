// Last updated: 6/26/2025, 7:58:13 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<=j){
            if(numbers[i]+numbers[j]==target){
                vector<int>arr;
                arr.push_back(i+1);
                arr.push_back(j+1);
                return arr;
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        vector<int>noo(2,-1);
        return noo;
    }
};