// Last updated: 6/26/2025, 7:52:49 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        set<int>st{n};
        for(int i=0;i<n;i++){
  st.insert(arr[i].second);
  if(arr[i].first!=0){
    ans++;
  }
  while(i+1<n && arr[i].first==arr[i+1].first){
    int next_small=*st.upper_bound(arr[i].second);
    int next_same=arr[i+1].second;
    if(next_small<next_same){
        break;
    }
    i++;
    st.insert(arr[i].second);
  }
        }
        return ans;
    }
};