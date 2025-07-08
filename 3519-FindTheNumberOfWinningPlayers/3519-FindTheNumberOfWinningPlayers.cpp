// Last updated: 7/9/2025, 1:32:04 AM

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        
        int m=pick.size();
        map<pair<int,int>,int> freq;
        for (int i = 0; i < m; i++) {
            int player_name = pick[i][0];
            int color  = pick[i][1];
            freq[{player_name, color}]++;
        }

       
        int winners = 0;
        map<int,int>vic;
    for (auto it : freq) {
            int player_name = it.first.first;
            int count = it.second;

            if (count >= player_name + 1 && vic[player_name]==0) {
                winners++;
                vic[player_name]=1;
            }
        }
        return winners;
    }

};