// JavaScript solution.

/**
 * @param {number} n
 * @return {string[]}
 */

var generateParenthesis = function(n) {
    let ans = [];
    var generate = function(left, right, s) {
        if (right === n) ans.push(s);
        if (left < n) generate(left+1, right, s+"(");
        if (right < left) generate(left, right+1, s+")");
    };
    generate(0, 0, "");
    return ans;
};
