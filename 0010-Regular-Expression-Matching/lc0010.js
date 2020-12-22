// JavaScript solution.

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */

var isMatch = function(s, p) {
    let ssize = s.length, psize = p.length;
    let dp = [...Array(ssize+1)].map(e => Array(psize+1).fill(false));
    dp[ssize][psize] = true;

    for (let i = ssize; i >= 0; i--) {
        for (let j = psize-1; j >= 0; j--) {
            let firstMatch = (i < ssize) && (s[i] === p[j] || p[j] === '.');
            if (j+1 < psize && p[j+1] === '*') {
                dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j]);
            } else {
                dp[i][j] = firstMatch && dp[i+1][j+1];
            }
        }
    }
    return dp[0][0];
};
