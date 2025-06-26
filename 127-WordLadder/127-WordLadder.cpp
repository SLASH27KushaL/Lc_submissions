// Last updated: 6/26/2025, 7:58:35 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>s(wordList.begin(),wordList.end());
        while(!(q.empty())){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char ori=word[i];
                for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(s.find(word)!=s.end()){
            s.erase(word);
            q.push({word,steps+1});
                }
                }
                word[i]=ori;
            }

        }
        return 0;
    }
};