// JavaScript solution.

/**
 * @param {number} x
 * @return {boolean}
 */

var isPalindrome = function(x) {
    if (x < 0 || (x%10 === 0 && x !== 0)) return false;
    let revert = 0;
    while (x > revert) {
        revert = revert * 10 + x % 10;
        x = ~~(x/10);
    }
    return x === revert || x === ~~(revert/10);
};
