// JavaScript solution.

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let hash = {};
    for (const str of strs) {
        const k = [...str].sort().join('');
        if (!hash[k]) {
            hash[k] = [str];
        } else {
            hash[k].push(str);
        }
    }
    return Object.values(hash);
};
