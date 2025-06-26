// Last updated: 6/26/2025, 7:56:06 PM
class Solution {
public:
    int fib(int n) {
        //base case
        if(n<=1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};