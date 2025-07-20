// Last updated: 7/20/2025, 7:14:01 PM
class Solution {
    static constexpr int MOD= 1e9+7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();    
       //convex quadri with at least one pair of horizontal sides  parallel to x axis;
        map<long long,int>yy;
        for(int i=0;i<n;i++){
           yy[points[i][1]]++;
        }
        vector<long long> cr(yy.size());
        long long inv2=(MOD+1)/2;
        for(auto &kv:yy){
            long long c=kv.second;
            if(c>=2){
            long long cc=(c%MOD)*((c-1)%MOD)%MOD;
            cc=cc*inv2%MOD;
            cr.push_back(cc);
        }
        }
        
       long long s=0;
        long long s2=0;
        for(auto x:cr){
            s=(s+x)%MOD;
            s2=(s2+x*x % MOD) % MOD;
        }

        long long ans=((s*s%MOD)-s2+MOD)%MOD;
        ans=ans*inv2%MOD;
        return int(ans);
        
    }
};