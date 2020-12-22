// JavaScript solution.

/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    if (!intervals.length) { return []; }
    intervals.sort((a,b) => a[0] - b[0]);
    let ans = [];
    for (let pair of intervals) {
        if (ans.length > 0 && pair[0] <= ans[ans.length-1][1]) {
            ans[ans.length-1][1] = Math.max(ans[ans.length-1][1], pair[1]);
        } else {
            ans.push([...pair]);
        }
    }
    return ans;
};
