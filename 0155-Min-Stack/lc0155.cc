// C++ solution.

class MinStack {
public:
    /** initialize your data structure here. */

    void push(const int x) {
        int curr_min = _stack.empty() ? x : _stack.back().second;
        _stack.push_back(std::make_pair(x, x < curr_min ? x : curr_min));
    }

    void pop() {
        if (!_stack.empty()) {
            _stack.pop_back();
        }
    }

    int top() {
        return _stack.back().first;
    }

    int getMin() {
        return _stack.back().second;
    }

private:
    std::deque<pair<int, int>> _stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */