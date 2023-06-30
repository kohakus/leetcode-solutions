// C++ solution.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m*n;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int x = matrix[mid/n][mid%n];
            if (x < target) {
                lo = mid + 1;
            } else if (x > target) {
                hi = mid;
            } else {
                return true;
            }
        }
        return false;
    }
};
