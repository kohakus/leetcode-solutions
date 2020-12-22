// C++ solution.

// simple DP solution.
// g[k][i]: max profit up to day i (included i) with at most k transactions (global optimal objective)
// l[k][i]: max profit up to day i (included i) with at most k transactions AND we sell at day i (local optimal objective)
//
// g[k][i] = max(g[k][i-1], l[k][i])
// l[k][i] = max_{j\in [0, i-1]} p[i] - p[j] + g[k-1][j-1]
//         = max(l[k][i-1], g[k-1][i-1]) + p[i] - p[i-1]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return _maxProfit(2, prices);
    }

private:
    int _maxProfit(const int k, vector<int>& prices) {
        if (prices.empty()) { return 0; }
        int n = prices.size();
        int ans = 0;

        if (k >= n/2) {
            int diff = 0;
            for (int i = 1; i < n; i++) {
                diff = prices[i] - prices[i-1];
                if (diff > 0) {
                    ans += diff;
                }
            }
            return ans;
        }

        vector<int> g(k+1, 0);
        vector<int> l(k+1, 0);
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i-1];
            int g_pre = g[0];
            for (int kk = 1; kk <= k; kk++) {
                l[kk] = std::max(l[kk], g_pre) + diff;
                g_pre = g[kk];
                g[kk] = std::max(g[kk], l[kk]);
            }
        }
        return g[k];
    }
};