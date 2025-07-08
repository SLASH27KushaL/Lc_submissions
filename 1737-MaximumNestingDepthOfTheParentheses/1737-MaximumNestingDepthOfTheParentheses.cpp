// Last updated: 7/9/2025, 1:33:32 AM
class Solution {
public:
    int maxDepth(string s) {
        int score=0;
        int max_score=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                score++;
            }
            else{
                if(s[i]==')'){
                score--;
                }
            }
            max_score=max(max_score,score);
        }
        return max_score;
    }
};