// JavaScript solution.

/**
 * @param {number} x
 * @return {number}
 */

var reverse = function(x) {
    let ret = 0;
    while (x !== 0) {
        let pop = x % 10;
        x = ~~(x/10);
        if (ret > 214748364 || (ret === 214748364 && pop > 7)) return 0;
        if (ret < -214748364 || (ret === -214748364 && pop < -8)) return 0;
        ret = ret * 10 + pop;
    }
    return ret;
};
