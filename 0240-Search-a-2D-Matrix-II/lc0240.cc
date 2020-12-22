// C++ solution.

// Time: O(m+n), Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) { return false; }
        int n = matrix.size();
        int m = matrix.front().size();
        int i = 0, j = m-1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) { return true; }
            target < matrix[i][j] ? j-- : i++;
        }
        return false;
    }
};