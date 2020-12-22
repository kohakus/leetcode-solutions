// JavaScript solution.

/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if (s.length < 1) return "";
    let start = 0, end = 0;
    for (let i = 0; i < s.length; i++) {
        let curr_len = Math.max(expand(s, i, i), expand(s, i, i+1));
        if (curr_len > end-start) {
            start = i - ~~((curr_len-1)/2);
            end = i + ~~(curr_len/2);
        }
    }
    return s.slice(start, end+1);
}

var expand = function(s, left, right) {
    while (left >= 0 && right < s.length && s[left] === s[right]) {
        left -= 1;
        right += 1;
    }
    return right-left-1;
}
