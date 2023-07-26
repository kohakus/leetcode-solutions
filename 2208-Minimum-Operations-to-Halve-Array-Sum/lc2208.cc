// C++ solution.

// Greedy
// Time complexity: O(NlogN)
class Solution {
public:
    int halveArray(vector<int>& nums) {
        std::priority_queue<double> pq(nums.begin(), nums.end());
        double nums_sum_half = std::accumulate(nums.begin(), nums.end(), 0.0) / 2.0;
        int res = 0;
        for (double cost = 0.0; cost < nums_sum_half; res++) {
            double half_num = pq.top() / 2;
            cost += half_num;
            pq.pop();
            pq.push(half_num);
        }
        return res;
    }
};