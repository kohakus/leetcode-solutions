// C++ solution.

// the key to set zeros in-place is to store zero states by using the first column and row.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) { return; }
        int m = matrix.size(), n = matrix.front().size();

        // check if the first column should be set.
        bool setcol0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                setcol0 = true;
                break;
            }
        }

        // strore zero states.
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // set zeros.
        for (int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 1; j--) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
            if (setcol0) { matrix[i][0] = 0; }
        }
    }
};