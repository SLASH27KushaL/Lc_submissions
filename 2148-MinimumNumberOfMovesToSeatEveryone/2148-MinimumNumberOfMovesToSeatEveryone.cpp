// Last updated: 6/26/2025, 7:54:54 PM
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans=0;
        for(int i=0;i<seats.size();i++){
         if(seats[i]>students[i]){
            ans+=seats[i]-students[i];
         }
         else{
            ans+=students[i]-seats[i];
         }
        }
return ans;

    }
};