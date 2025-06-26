// Last updated: 6/26/2025, 7:55:57 PM
class Solution {
public:
    void dfs(vector<set<int>>& adj, int sv, int& mn, vector<int>& vis) {
        vis[sv] = 1;
        mn = min(mn, sv);
        for (auto v : adj[sv]) {
            if (!vis[v]) {
                dfs(adj, v, mn, vis);
            }
        }
    }

    int findmin(vector<set<int>>& adj, int c) {
        int mn = c;
        vector<int> vis(26, 0);
        dfs(adj, c, mn, vis);
        return mn;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<set<int>> adj(26); // 26 letters only

        for (int i = 0; i < n; i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            adj[u].insert(v);
            adj[v].insert(u);
        }

        string ans = "";
        for (char ch : baseStr) {
            int c = ch - 'a';
            int s = findmin(adj, c);
            ans += (char)(s + 'a');
        }

        return ans;
    }
};
