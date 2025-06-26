// Last updated: 6/26/2025, 8:00:09 PM

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
      int l=0,r=0;
      int maxlen=0;
      vector<int>mpp(256,-1);
      while(r<s.size()){
        if(mpp[s[r]]!=-1){
            l=max(mpp[s[r]]+1,l);
        }
        mpp[s[r]]=r;
        maxlen=max(maxlen,r-l+1);
        r++;

      }
      return maxlen;
    }
};
