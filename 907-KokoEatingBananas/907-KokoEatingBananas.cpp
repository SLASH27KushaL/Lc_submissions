// Last updated: 6/26/2025, 7:56:20 PM
#include <bits/stdc++.h>

class Solution {

public:
long long function(vector<int>vec,int speed){
    long long hours=0;
    for(int i=0;i<vec.size();i++){
        hours += ceil((double)vec[i] / (double)speed);
    }
    return hours;
}    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int max=piles[0];
       
       for(int i=0;i<piles.size();i++){
        if(piles[i]>max){
            max=piles[i];
        }}


       int high=max;
       int low=1;
       int ans=INT_MAX;

      while (high>=low){
        int mid=(low+high)/2;
        if(function(piles,mid)<=h){
            ans=min(ans,mid);
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }

  return ans;  }
};