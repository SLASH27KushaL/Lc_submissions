// Last updated: 6/26/2025, 7:56:56 PM
class Solution {
public:
    void dfs(int node, vector<vector<int>>& list, vector<int>& vis) {
     vis[node]=1;
     for(auto it:list[node]){
        if(vis[it]==0){
    dfs(it,list,vis);
        }
     }
    } 

    int findCircleNum(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<vector<int>>list(n);
    //to change adjacency matrix to list
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1 &&i!=j){
              list[i].push_back(j);
              list[j].push_back(i);
            }
        }
    }
    vector<int>vis(n,0);
    int count=0;
 for(int i=0;i<n;i++){
    if(vis[i]==0){
        count++;
        dfs(i,list,vis);
    }
 }
 return count;
    }
};

