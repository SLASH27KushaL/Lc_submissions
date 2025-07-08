// Last updated: 7/9/2025, 1:33:53 AM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        }
        if(q.size()==2){
            int v1=q.top();
            q.pop();
            int v2=q.top();
            q.pop();
            if(v1!=v2){
             return v1-v2;
            }
            else{
                return 0;
            }
        }
        while((q.size()>1)){
            int v1=q.top();
            q.pop();
            int v2=q.top();
            q.pop();
            if(v1!=v2){
             v1=v1-v2;
             q.push(v1);
            }
            else{
              if(q.size()==0){
                return 0;
              }
            }
        }
        return q.top();
    }
};