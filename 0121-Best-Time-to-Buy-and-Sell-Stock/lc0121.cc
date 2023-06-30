// C++ solution.

// DP method.
// State f[i]: target of the corresponding sub-problem of range [0 ... i]
// f[i] = max(f[i-1], a[i] - m[i]) if a[i] > m[i-1]
// f[i] = f[i-1] if a[i] <= m[i-1]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) { return 0; }
        int min_proces = prices.front();
        int max_profit = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            if (prices[i] <= min_proces) {
                min_proces = prices[i];
            } else {
                max_profit = std::max(max_profit, prices[i] - min_proces);
            }
        }
        return max_profit;
    }
};