// Last updated: 6/26/2025, 7:55:48 PM
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int max=arr1[0];
    for(int i=0;i<arr1.size();i++){
        if(arr1[i]>max){
            max=arr1[i];
        }
    }
  vector<int>hash(max+1,0);

  for(int i=0;i<arr1.size();i++){
    hash[arr1[i]]++;
  }
vector<int>output;

for(int i=0;i<arr2.size();i++){
    while(hash[arr2[i]]){
        output.push_back(arr2[i]);
        hash[arr2[i]]--;

    }}
for(int i=0;i<hash.size();i++){
    while(hash[i]){
        output.push_back(i);
        hash[i]--;
    }    
}
    
return output;







    }
};