// Last updated: 8/11/2025, 3:40:24 AM
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
    //change the answer key
    //find where it will be the most effective
    int i=0;
    int j=0;
    //find max count of consecutive Ts and max count of consecutive Fs;
    int max_T=0;
    int max_F=0;
   

    //run this for true once and then for false once
    
    int count=0;
    while(j<n){
        //longest T possible
        if(answerKey[j]=='F'){
            count++;
        }
        while(count>k){
            if(answerKey[i]=='F'){
                count--;
               
            }
            i++;
        }
        max_T=max(max_T,j-i+1);
        j++;

    }


    int l=0;
    int r=0;
    count=0;
    while(r<n){
        if(answerKey[r]=='T'){
         count++;
        }
        while(count>k){
            if(answerKey[l]=='T'){
               count--;
            }
           l++;
        }
        max_F=max(max_F,r-l+1);
    r++;
    }

    return max(max_T,max_F);
    //longest F possible
    }
};