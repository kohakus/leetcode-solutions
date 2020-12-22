// C++ solution.

// Greedy solution.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            int diff = prices[i+1] - prices[i];
            if (diff > 0) {
                ans += diff;
            }
        }
        return ans;
    }
};