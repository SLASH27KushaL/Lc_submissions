// Last updated: 7/9/2025, 1:34:01 AM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //make it a min heap based on the dis
           priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        for(int i=0;i<points.size();i++){
            int dis=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            pq.push({dis,{points[i][0],points[i][1]}});
        }
        vector<vector<int>>arr;
        for(int i=0;i<k;i++){
             vector<int>p;
             pair<int,pair<int,int>>a;
             a=pq.top();
             pq.pop();
             p.push_back(a.second.first);
             p.push_back(a.second.second);
         arr.push_back(p);
        }
        return arr;
    }
};