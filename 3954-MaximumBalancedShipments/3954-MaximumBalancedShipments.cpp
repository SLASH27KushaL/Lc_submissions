// Last updated: 8/6/2025, 7:43:29 PM
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
     //balanced if weight of last parcel is strictly less than    
    //we need to return the maximum possible number of balanced shipments
    int i=0;
    int j=0;
    int maxi=INT_MIN;
    int count=0;
    while(j<n){
        maxi=max(maxi,weight[j]);
        if(maxi!=weight[j]){
            count++;
            j++;
            i=j;
            maxi=INT_MIN;
        }
  else{
    j++;
  }
    }
    return count;
    }
};