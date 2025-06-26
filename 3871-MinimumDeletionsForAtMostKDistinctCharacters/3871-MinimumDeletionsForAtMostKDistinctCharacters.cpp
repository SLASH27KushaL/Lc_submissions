// Last updated: 6/26/2025, 7:52:35 PM
class Solution {
public:
    int minDeletion(string s, int k) {
        map<char,int> hash;
        for(char c : s){
            hash[c]++;
        }

        int count = hash.size(); // number of unique characters

        if(count <= k){
            return 0;
        }
        else {
          
            vector<pair<char, int>> freqVec(hash.begin(), hash.end());
            sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
                return a.second < b.second;
            });

            int operations = 0;
            int excess = count - k;

            for (int i = 0; i < excess; ++i) {
                operations += freqVec[i].second; 
            }

            return operations;
        }

        return -1;
    }
};
