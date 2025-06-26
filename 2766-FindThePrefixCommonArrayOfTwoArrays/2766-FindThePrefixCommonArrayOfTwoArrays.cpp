// Last updated: 6/26/2025, 7:54:01 PM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
       vector<int>ans;
       map<int,int>hash;
       int cnt=0;
       for(int i=0;i<A.size();i++)
      {
         hash[A[i]]++;
         if(hash[A[i]]==2 ){
            cnt++;
         }
        hash[B[i]]++;
        if(hash[B[i]]==2){
            cnt++;
        }
         ans.push_back(cnt);
      }
      return ans;

      }
      
      
    };
