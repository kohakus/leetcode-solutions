// JavaScript solution.

/**
 * @param {string} s
 * @return {number}
 */

var lengthOfLongestSubstring = function(s) {
    let poslog = new Map();
    let start = 0, ans = 0;
    for (const [cursor, val] of [...s].entries()) {
        query_pos = poslog.get(val);
        if (query_pos !== undefined && query_pos > start) {
            start = query_pos;
        }
        ans = Math.max(ans, cursor-start+1);
        poslog.set(val, cursor+1);
    }
    return ans;
};
