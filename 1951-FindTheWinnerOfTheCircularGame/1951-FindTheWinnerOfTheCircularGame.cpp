// Last updated: 8/11/2025, 3:40:39 AM
#include <vector>
using namespace std;

class Solution {
public:
    
    int josephus(int n, int k) {
        int winner = 0;
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        return winner + 1; 
    }

    int findTheWinner(int n, int k) {
        return josephus(n, k);
    }
};
