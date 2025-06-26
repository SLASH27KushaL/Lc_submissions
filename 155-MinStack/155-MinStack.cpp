// Last updated: 6/26/2025, 7:58:14 PM
class MinStack {
public:
    stack<pair<int, int>> s;

    MinStack() {}

    void push(int val) {
        int currentMin = s.empty() ? val : min(s.top().second, val);
        s.push({val, currentMin});
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }

    int top() {
        if (!s.empty()) {
            return s.top().first;
        }
        return -1; // Optional: Handle empty stack case
    }

    int getMin() {
        if (!s.empty()) {
            return s.top().second;
        }
        return -1; // Optional: Handle empty stack case
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */