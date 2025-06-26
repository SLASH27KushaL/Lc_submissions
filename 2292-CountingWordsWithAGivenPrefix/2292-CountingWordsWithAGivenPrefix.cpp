// Last updated: 6/26/2025, 7:54:35 PM
class Solution {
public:
bool hasPrefix(string& str,string& prefix) {
    return str.find(prefix) == 0; // Prefix matches at the start (index 0)
}    
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int i=0;i<words.size();i++){
        if(hasPrefix(words[i],pref)){
            count++;
        }

        }
        return count;
    }
};