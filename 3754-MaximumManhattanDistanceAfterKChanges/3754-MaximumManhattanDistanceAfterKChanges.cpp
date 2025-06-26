// Last updated: 6/26/2025, 7:53:05 PM
class Solution {
public:
    int maxDistance(string s, int k) {
        int lat = 0, lon = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    lat++;
                    break;
                case 'S':
                    lat--;
                    break;
                case 'E':
                    lon++;
                    break;
                case 'W':
                    lon--;
                    break;
            }
            ans = max(ans, min(abs(lat) + abs(lon) + k * 2, i + 1));
        }
        return ans;
    }
};