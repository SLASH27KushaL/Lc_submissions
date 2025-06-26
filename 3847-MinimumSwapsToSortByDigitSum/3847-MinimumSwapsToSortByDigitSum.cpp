// Last updated: 6/26/2025, 7:52:44 PM
class Solution {
public:
    int digit(int n){
int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
}
    int minSwaps(vector<int>& nums) {
  int n = nums.size();
    vector<tuple<int,int,int>> A;
    A.reserve(n);
    
    for (int i = 0; i < n; i++) {
        A.emplace_back(digit(nums[i]), nums[i], i);
    }
    sort(A.begin(), A.end(), [](auto &a, auto &b) {
        if (get<0>(a) != get<0>(b))
            return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    });
    
    vector<int> to(n);
    for (int sortedPos = 0; sortedPos < n; sortedPos++) {
        int origIdx = get<2>(A[sortedPos]);
        to[origIdx] = sortedPos;
    }
    
    vector<bool> visited(n,false);
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || to[i] == i) 
            continue;
        int cycleLen = 0;
        int cur = i;
        while (!visited[cur]) {
            visited[cur] = true;
            cur = to[cur];
            cycleLen++;
        }
        if (cycleLen > 0) 
            swaps += cycleLen - 1;
    }
    return swaps;
        
    }
};