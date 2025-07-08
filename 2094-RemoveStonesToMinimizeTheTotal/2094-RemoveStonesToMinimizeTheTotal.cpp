// Last updated: 7/9/2025, 1:33:18 AM
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>q;
        for(int i=0;i<piles.size();i++){
            q.push(piles[i]);
        }
        for(int i=0;i<k;i++){
        int val=q.top();
        q.pop();
        val-=ceil(val/2);
        q.push(val);   
        }
        int s=0;
        while(!(q.empty())){
            s+=q.top();
            q.pop();
        }
        return s;
    }
};