// Last updated: 6/26/2025, 7:57:53 PM
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }


        //topo sort code
        queue<int>q;
        for(int i=0;i<n;i++)
        {
        if(indegree[i]==0){
         q.push(i);
        }
        }
        vector<int>topo;
        while(!(q.empty())){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
             indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
            }
        }
        if(topo.size()==n){
            return topo;
        }
        vector<int>ans;
    return ans;

    }
};
