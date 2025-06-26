// Last updated: 6/26/2025, 7:52:38 PM
class Solution {
public:
    #define ll long long
    ll modulo=1e9+7;
    ll facto(ll n){
      if(n==1){
        return 1;
      }
      return (n*(facto(n-1)))%modulo;
    }
    int countPermutations(vector<int>& complexity) {
        ll  n=complexity.size();
        ll mini=complexity[0];
        for(ll i=1;i<n;i++){
            
            if(complexity[i]<=mini)
            {
                return 0;
                break;
            }
        }
        ll ans=facto(n-1);
        return ans%modulo;

    }
};