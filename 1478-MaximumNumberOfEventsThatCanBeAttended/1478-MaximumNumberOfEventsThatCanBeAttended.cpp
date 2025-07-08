// Last updated: 7/9/2025, 1:33:41 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        if (n == 0) return 0;

       
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

       
        priority_queue<int, vector<int>, greater<int>> pq;
        int day = events[0][0];
        int i = 0;
        int count = 0;

        
        while (i < n || !pq.empty()) {
           
            if (pq.empty() && i < n && day < events[i][0]) {
                day = events[i][0];
            }

            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

           
            if (!pq.empty()) {
                pq.pop();
                count++;
            }

            
            day++;
        }

        return count;
    }
};
