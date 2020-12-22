// C++ solution.

// monostack method.
// similar to LeetCode84.
// every row in the matrix is viewed as the ground with some buildings on it.
// the building height is the count of consecutive 1s from that row to above rows.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix.front().size();
        vector<int> heights(n+1, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            // update height histogram
            for (int j = 0; j < n; j++) {
                heights[j] = (matrix[i][j] == '1') ? (heights[j] + 1) : 0;
            }
            // maintain a non-decreasing sequence by using monostack,
            // storing indices to get the width of histogram blocks quickly.
            stack<int> monostack;
            monostack.push(0);
            for (int j = 1; j <= n; j++) {
                while (!monostack.empty() && heights[j] < heights[monostack.top()]) {
                    int h = heights[monostack.top()];
                    monostack.pop();
                    int prev = monostack.empty() ? -1 : monostack.top();
                    int w = j - prev - 1;
                    ans = std::max(ans, h*w);
                }
                monostack.push(j);
            }
        }
        return ans;
    }
};