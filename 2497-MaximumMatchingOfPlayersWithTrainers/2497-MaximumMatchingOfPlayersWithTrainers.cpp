// Last updated: 7/15/2025, 4:01:58 PM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0;
        int j=0;
        int count=0;
        int m=trainers.size();
        int n=players.size();
        while(i<n && j<m){
           if(players[i]<=trainers[j]){
            count++;
            i++;
           }
           j++;
        }
        return count;
    }
};