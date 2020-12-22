// JavaScript solution.

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let i = 0, j = 0;
    let sm = 0, star = -1;
    let m = s.length, n = p.length;
    while (i < m) {
        if (j < n && (s[i] === p[j] || p[j] === '?')) {
            i++;
            j++;
        } else if (j < n && p[j] === '*') {
            star = j++;
            sm = i;
        } else if (star >= 0) {
            j = star+1;
            i = ++sm;
        } else { return false; }
    }
    while (j < n && p[j] === '*') { j++; }
    return j === n;
};
