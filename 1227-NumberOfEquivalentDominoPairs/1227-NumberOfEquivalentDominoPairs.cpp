// Last updated: 6/26/2025, 7:55:46 PM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count=0;
        map<pair<int,int>,int>hash;
        for(int i=0;i<dominoes.size();i++){
           if(hash[{dominoes[i][0],dominoes[i][1]}]==0 && hash[{dominoes[i][1],dominoes[i][0]}]>0){
              hash[{dominoes[i][1],dominoes[i][0]}]++;
           }
           else if(hash[{dominoes[i][0],dominoes[i][1]}]==0 && hash[{dominoes[i][1],dominoes[i][0]}]==0){
            hash[{dominoes[i][0],dominoes[i][1]}]++;
           }
   else{
    hash[{dominoes[i][0],dominoes[i][1]}]++;
   }
        }

for (const auto& it : hash) {
    int res=it.second;
    count+=(res*(res-1))/2;
}

        return count;
    }
};