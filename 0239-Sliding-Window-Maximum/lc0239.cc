// C++ solution.

class MonoQueue {
public:
    void push(int val) {
        int cnt = 0;
        while (!_monoque.empty() && _monoque.back().first < val) {
            cnt += _monoque.back().second + 1;
            _monoque.pop_back();
        }
        _monoque.emplace_back(val, cnt);
    }

    void pop() {
        if (_monoque.front().second > 0){
            _monoque.front().second--;
        } else {
            _monoque.pop_front();
        }
    }

    int front() const {
        return _monoque.front().first;
    }

    bool empty() const {
        return _monoque.empty();
    }

private:
    std::deque<std::pair<int, int>> _monoque;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        MonoQueue monoque;
        k = std::min(k, static_cast<int>(nums.size()));
        for (int i = 0; i < k-1; i++) {
            monoque.push(nums[i]);
        }
        for (int i = k-1; i < nums.size(); i++) {
            monoque.push(nums[i]);
            ans.push_back(monoque.front());
            monoque.pop();
        }
        return ans;
    }
};