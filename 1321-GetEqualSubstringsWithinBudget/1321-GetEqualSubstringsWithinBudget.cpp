// Last updated: 8/11/2025, 3:41:11 AM
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        //we have to change s to t
        //cost for each character change is abs(s[i]-t[i])
        int i=0;
        int j=0;
        int cost=0;
        int ans=0;
        while(j<n){
            if(s[j]!=t[j]){
              cost+=abs(s[j]-t[j]);
            }
            while(cost>maxCost){
                if(s[i]!=t[i]){
                    cost-=abs(s[i]-t[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;

    }
};