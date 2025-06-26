// Last updated: 6/26/2025, 7:53:44 PM
class Solution {
public:
bool hasPrefix(string& str,string& prefix) {
    return str.find(prefix) == 0; // Prefix matches at the start (index 0)
}
bool hasSuffix(string& str,string& suffix) {
    if (suffix.size() > str.size()) return false;
    return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i==j){
                    continue;
                }
                else{
                    if(hasPrefix(words[i],words[j]) && hasSuffix(words[i],words[j])){
                      if(i>j){
                        count++;
                      }
                    }
                }
            }
        }
        return count;
    }
};