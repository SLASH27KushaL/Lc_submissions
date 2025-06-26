// Last updated: 6/26/2025, 7:53:09 PM
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers, m = events.size();
        vector<int> count(n, 0), order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            int ta = stoi(events[a][1]), tb = stoi(events[b][1]);
            if (ta != tb) return ta < tb;
            bool offA = events[a][0] == "OFFLINE";
            bool offB = events[b][0] == "OFFLINE";
            return offA && !offB;
        });
        vector<int> offlineUntil(n, 0);
        for (int i : order) {
            auto &e = events[i];
            int t = stoi(e[1]);
            if (e[0] == "OFFLINE") {
                offlineUntil[stoi(e[2])] = t + 60;
            } else {
                const string &tok = e[2];
                if (tok == "ALL") {
                    for (int u = 0; u < n; ++u) count[u]++;
                } else if (tok == "HERE") {
                    for (int u = 0; u < n; ++u)
                        if (offlineUntil[u] <= t) count[u]++;
                } else {
                    int pos = 0, len = tok.size();
                    while (pos < len) {
                        pos += 2;
                        int start = pos;
                        while (pos < len && isdigit(tok[pos])) ++pos;
                        count[stoi(tok.substr(start, pos - start))]++;
                        if (pos < len && tok[pos] == ' ') ++pos;
                    }
                }
            }
        }
        return count;
    }
};

