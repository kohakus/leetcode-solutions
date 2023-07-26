// C++ solution.

// DP.
// after the trade of the ith day:
//     f0[i]: if stock unsell
//     f1[i]: no stock, but cannot buy, i.e. cooldown
//     f2[i]: no stock, and be able to buy
// state transfers:
//     f0[i] = max(f0[i-1], f2[i-1] - a[i])
//     f1[i] = f0[i-1] + a[i]
//     f2[i] = max(f2[i-1], f1[i-1])
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        int tmp = f1;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            tmp = f1;
            f1 = f0 + prices[i];
            f0 = std::max(f0, f2 - prices[i]);
            f2 = std::max(tmp, f2);
        }
        return std::max(f1, f2);
    }
};