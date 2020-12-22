// JavaScript solution.

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    candidates.sort((a,b) => a-b);
    let res = [], ans = [];

    var backtrack = function(cur, residual) {
        if (residual === 0) { ans.push([...res]); }
        else {
            for (let i = cur; i < candidates.length; i++) {
                if (residual >= candidates[i]) {
                    res.push(candidates[i]);
                    backtrack(i, residual-candidates[i]);
                    res.pop();
                }
            }
        }
    };

    backtrack(0, target);
    return ans;
};
