// Last updated: 6/26/2025, 7:55:11 PM
class Solution{
public:
    vector<int> minOperations(string boxes) {
        vector<int>arr;
        for(int i=0;i<boxes.size();i++){
            int count=0;
            for(int j=0;j<boxes.size();j++){
            if(j==i){
                continue;
            }        
            else{
                if(boxes[j]=='1'){
                     count+=abs(i-j);   
                }
            }
            }
            arr.push_back(count);

        }
        return arr;
    }
};