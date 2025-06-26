// Last updated: 6/26/2025, 7:57:47 PM
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() { }

    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            throw std::out_of_range("Stack is empty!");
        }
        int n = q.front();
        q.pop();
        return n;
    }

    int top() {
        if (q.empty()) {
            throw std::out_of_range("Stack is empty!");
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */