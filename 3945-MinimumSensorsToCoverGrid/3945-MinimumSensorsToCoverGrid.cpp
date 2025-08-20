// Last updated: 8/20/2025, 8:16:11 PM
class Solution {
public: 
    int minSensors(int n, int m, int k) {
        //number of rows needed
        int one=(n%(2*k+1)==0)?(n/(2*k+1)):((n/(2*k+1))+1);
        //number of columns needed
        int two=(m%(2*k+1)==0)?(m/(2*k+1)):((m/(2*k+1))+1);
        long long ans=one*two;
        return ans;
    }
};