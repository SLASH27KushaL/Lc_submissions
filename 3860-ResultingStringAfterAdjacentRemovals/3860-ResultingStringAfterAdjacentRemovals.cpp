// Last updated: 6/26/2025, 7:52:40 PM
class Solution {
public:
    string resultingString(string s) {
        int n = s.size();
        if (n < 2) return s;
        vector<int> nx(n), pv(n);
        vector<bool> al(n, true);
        for (int i = 0; i < n; i++) {
            nx[i] = i + 1 < n ? i + 1 : -1;
            pv[i] = i - 1 >= 0 ? i - 1 : -1;
        }
        auto f = [&](char x, char y) {
            int d = abs(x - y);
            return d == 1 || d == 25;
        };
        set<int> c;
        for (int i = 0; i + 1 < n; i++)
            if (f(s[i], s[i+1])) c.insert(i);
        while (!c.empty()) {
            int i = *c.begin(); c.erase(c.begin());
            int j = nx[i];
            if (j < 0 || !al[i] || !al[j] || !f(s[i], s[j])) continue;
            al[i] = al[j] = false;
            int L = pv[i], R = nx[j];
            if (L != -1) nx[L] = R;
            if (R != -1) pv[R] = L;
            if (L != -1 && R != -1 && al[L] && al[R] && f(s[L], s[R]))
                c.insert(L);
        }
        int h = 0;
        while (h < n && !al[h]) h++;
        if (h == n) return "";
        string r;
        for (int i = h; i != -1; i = nx[i])
            if (al[i]) r.push_back(s[i]);
        return r;
    }
};
