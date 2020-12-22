// JavaScript solution.

/**
 * @param {string} digits
 * @return {string[]}
 */

var letterCombinations = function(digits) {
    let sz = digits.length;
    let ans = [];
    let res = Array(sz).fill('0');
    let dig =  ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    if (sz === 0) { return ans; }

    function backtracking(depth) {
        if (depth === sz) {
            ans.push(res.join(""));
            return;
        }

        let button = digits[depth];
        for (let letter of dig[button]) {
            res[depth] = letter;
            backtracking(depth+1);
        }
    }

    backtracking(0);
    return ans;
};

