// Last updated: 6/26/2025, 7:57:16 PM
class Solution {
public:
 int possible(vector<int> arr,int capacity,int m){
int page=0;
int stud=1;
for(int i=0;i<arr.size();i++){
  if (page + arr[i] > capacity) {
    stud += 1;
    page = arr[i];
  }

  else {
    page += arr[i];
  }
}

return stud;
}

public:
    int splitArray(vector<int>& nums, int k) {
       

int max=nums[0];
    for(int i=0;i<nums.size();i++){
        if(nums[i]>max){
            max=nums[i];
        }
    }


    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }


    int low=max;
    int high=sum;
    if(k>nums.size()){
        return -1;
    }
    while(high>=low){
        int mid=low+((high-low)/2);
        if(possible(nums,mid,k)<=k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
return low;
    



    }
};