// Last updated: 6/26/2025, 7:58:43 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            ans=max(cost,ans);
            mini=min(mini,prices[i]);
        }
        return ans;
    }
};