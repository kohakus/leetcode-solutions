// C++ solution.

// Naive DP.
// Time complexity: O(NK)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int nums_len = nums.size();
        std::vector<int> dp(nums_len, 0);
        for (int i = 0; i < nums_len; i++) {
            int intvs = std::max(0, i-k);
            dp[i] = nums[i] + *std::max_element(dp.begin()+intvs, dp.begin()+i);
        }
        return dp.back();
    }
};

// + Priority queue
// Time complexity: O(NlogN)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int nums_len = nums.size();
        std::priority_queue<std::pair<int, int>> pq;

        // initial state
        pq.emplace(nums[0], 0);
        int ans = pq.top().first;

        for (int i = 1; i < nums_len; i++) {
            while (pq.top().second < i-k) {
                pq.pop();
            }
            ans = pq.top().first + nums[i];
            pq.emplace(ans, i);
        }
        return ans;
    }
};

// + Monoqueue
// Time complexity: O(N)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int nums_len = nums.size();
        std::deque<std::pair<int, int>> monoq;

        // initial state
        monoq.emplace_back(nums[0], 0);
        int ans = monoq.front().first;

        for (int i = 1; i < nums_len; i++) {
            while (!monoq.empty() && monoq.front().second < i-k) {
                monoq.pop_front();
            }
            ans = monoq.front().first + nums[i];
            while (!monoq.empty() && ans >= monoq.back().first) {
                monoq.pop_back();
            }
            monoq.emplace_back(ans, i);
        }
        return ans;
    }
};