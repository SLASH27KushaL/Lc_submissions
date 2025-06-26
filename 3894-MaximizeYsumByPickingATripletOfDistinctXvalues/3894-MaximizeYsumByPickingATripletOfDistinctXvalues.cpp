// Last updated: 6/26/2025, 7:52:26 PM
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        //greedy // binary search
        int n=y.size();
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={y[i],i};
        }
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(x[i]);
            
        }
        if(s.size()<3){
            return -1;
        }
        map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[x[i]]=max(hash[x[i]],y[i]);
        }
        sort(arr.rbegin(),arr.rend());
        int sum=0;
        int count=0;
        set<int>used;
        for(int i=0;i<n;i++){
            int val=arr[i].first;
        int ind=arr[i].second;
        int maxi=hash[x[ind]];
        if(val!=maxi || used.count(x[ind])){
            continue;
        }
       else{
           sum+=val;
           count++;
           used.insert(x[ind]);
           if(count==3){
               break;
           }
       }
        }
        return sum;
        
    }
};