// Last updated: 6/26/2025, 7:54:58 PM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dist(n, 1e18); 
        vector<int> ways(n, 0);          
        ways[0] = 1;
        dist[0] = 0;
        int modo = 1e9 + 7;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto [ne, we] : adj[node]){
                if(dis + we < dist[ne]){
                    dist[ne] = dis + we;
                    pq.push({dist[ne], ne});
                    ways[ne] = ways[node];
                }
                else if(dis + we == dist[ne]){
                    ways[ne] = (ways[ne] + ways[node]) % modo;
                }
            }
        }
        return ways[n-1] % modo;
    }
};
