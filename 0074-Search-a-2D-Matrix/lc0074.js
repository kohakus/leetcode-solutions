// JavaScript solution.

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let m = matrix.length;
    if (m > 0) {
        let n = matrix[0].length;
        let lo = 0, hi = m * n;
        while (lo < hi) {
            let mid = (lo + hi) >> 1;
            let x = matrix[Math.trunc(mid/n)][mid%n];
            if (x < target) { lo = mid+1; }
            else if (x > target) { hi = mid; }
            else { return true; }
        }
    }
    return false;
};
