// Last updated: 6/26/2025, 7:56:33 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto& iter : adj[node]) {
                int adj_node = iter.first;
                int adj_wei = iter.second;

                if(cost + adj_wei < dist[adj_node]) {
                    dist[adj_node] = cost + adj_wei;
                    q.push({stops + 1, {adj_node, dist[adj_node]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
