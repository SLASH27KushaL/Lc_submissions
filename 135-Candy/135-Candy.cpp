// Last updated: 6/26/2025, 7:58:31 PM
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
  vector<int>arr(n,1);
  for(int i=1;i<n;i++){
    if(ratings[i]>ratings[i-1]){
        arr[i]=arr[i-1]+1;
    }
  }
  for(int i=n-2;i>=0;i--){
    if(ratings[i]>ratings[i+1]){
        arr[i]=max(arr[i],arr[i+1]+1);

    }
  }
  int s=0;
  for(int i=0;i<n;i++){
    s+=arr[i];
  }
  return s;
    }
};