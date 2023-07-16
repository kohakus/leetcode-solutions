// C++ solution.

// Priority queue.
// Time complexity: O(NlogN)
// Space complexity: O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int,int>> pq;
        for (int i = 0; i < k; i++) {
            pq.emplace(nums[i], i);
        }

        int nums_len = nums.size();
        std::vector<int> ans(nums_len-k+1, 0);

        ans[0] = pq.top().first;
        for (int i = k; i < nums_len; i++) {
            pq.emplace(nums[i], i);
            while (pq.top().second < i-k+1) {
                pq.pop();
            }
            ans[i-k+1] = pq.top().first;
        }
        return ans;
    }
};

// MonoQueue.
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) { dq.pop_back(); }
            dq.push_back(i);
        }

        int nums_len = nums.size();
        std::vector<int> ans(nums_len-k+1, 0);

        ans[0] = nums[dq.front()];
        for (int i = k; i < nums_len; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) { dq.pop_back(); }
            dq.push_back(i);
            while (dq.front() < i-k+1) {
                dq.pop_front();
            }
            ans[i-k+1] = nums[dq.front()];
        }
        return ans;
    }
};