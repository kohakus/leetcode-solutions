// JavaScript solution.

/**
 * @param {string} s
 * @return {boolean}
 */

var isValid = function(s) {
    let st = [];
    for (let c of [...s]) {
        if (c === '{') st.push('}');
        else if (c === '(') st.push(')');
        else if (c === '[') st.push(']');
        else {
            if (st.length === 0 || c !== st.pop()) return false;
        }
    }
    return st.length === 0;
};
