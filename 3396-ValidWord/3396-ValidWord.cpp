// Last updated: 7/15/2025, 4:01:33 PM
class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        //minimum of 3 characters
        //one vowel
        //one consonant
        if(n<3){
            return false;
        }
        int count1=0;
        int count2=0;
      map<char,int>hash;
     hash['a']++;
     hash['e']++;
     hash['i']++;
     hash['o']++;
     hash['u']++;
     hash['A']++;
     hash['E']++;
     hash['I']++;
     hash['O']++;
     hash['U']++;
        for(int i=0;i<n;i++){
           if(!(isalnum(word[i]))){
               return false;
           }
           else{
            if(hash[word[i]]){
                count1++;
            }
            else{
                if(!(word[i]-'0'>=0 && word[i]-'0'<=9)){
                    count2++;
                }
            }
           }
        }
       return  (count1 && count2)?1:0;
    }
};