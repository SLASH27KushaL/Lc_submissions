// Last updated: 6/26/2025, 7:56:17 PM
class StockSpanner {
public:
 
  stack<pair<int,int>>s1;
  int index=-1;

    StockSpanner() {
     index=-1;
    
    }
    
    int next(int price) {
        index++;
        while(!s1.empty() && s1.top().first<=price){
           s1.pop();
        }
        int ans=index;
        int span = ans - (s1.empty() ? -1 : s1.top().second);
        s1.push({price, index});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */