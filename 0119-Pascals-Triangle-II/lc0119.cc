// C++ solution.

// Linear time to generate nth row of Pascal Triangle.
// Note: n start from 0.
// C(n, 0) = 1; C(n, n) = 1;
// C(n, k) = (n-k+1)/k * C(n, k-1), 1 <= k <= n;
class Solution {
public:
    vector<int> getRow(int row_index) {
        vector<int> ans(row_index + 1, 1);
        for (int k = 1; k <= row_index; k++) {
            // Note that the calculation order here is important.
            int64_t next_val = static_cast<int64_t>(ans[k-1]) * (row_index - k + 1) / k;
            ans[k] = static_cast<int>(next_val);
        }
        return ans;
    }
};