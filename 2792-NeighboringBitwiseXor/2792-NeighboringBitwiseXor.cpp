// Last updated: 6/26/2025, 7:54:00 PM
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
     int res=0;
     for(int i=0;i<derived.size();i++){
        res=res^derived[i];
     }  
     if(res){
        return false;
     } 
     return true;
    }
};