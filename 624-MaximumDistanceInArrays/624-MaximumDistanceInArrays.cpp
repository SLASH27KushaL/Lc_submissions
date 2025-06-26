// Last updated: 6/26/2025, 7:56:50 PM
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        vector<pair<int,int>>mini;
        vector<pair<int,int>>maxi;
        for(int i=0;i<m;i++){
            mini.push_back({*min_element(arrays[i].begin(),arrays[i].end()),i});
            maxi.push_back({*max_element(arrays[i].begin(),arrays[i].end()),i});
        }
      sort(mini.begin(),mini.end());
      sort(maxi.rbegin(),maxi.rend());
     int i=0;int j=0;
     int maxx=INT_MIN;
     for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(maxi[i].second==mini[j].second)
{
    continue;
}
else{
    maxx=max(maxx,maxi[i].first-mini[j].first);
}        
}
}
     return maxx;
    }
};