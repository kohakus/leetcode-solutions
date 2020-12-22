// JavaScript solution.

/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */

var convert = function(s, numRows) {
    if (numRows === 1) return s;
    let ret = new Array(numRows).fill("");
    let rowCursor = 0;
    let trigger = false;

    for (c of [...s]) {
        ret[rowCursor] += c;
        rowCursor += trigger? -1 : 1;
        if (rowCursor === 0 || rowCursor === numRows-1) {
            trigger = !trigger;
        }
    }

    return ret.join('');
};
