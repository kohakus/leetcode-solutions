// Rust solution.

use std::cmp;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if (s.len() < 1) { return "".to_string(); }
        let (mut start, mut end): (usize, usize) = (0, 0);
        for i in 0..(s.len()) {
            let len_odd = Solution::expand(&s[..], i, i);
            let len_even = Solution::expand(&s[..], i, i+1);
            let len = cmp::max(len_odd, len_even);
            if (len > end-start) {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        String::from(&s[start..=end])
    }
}

impl Solution {
    fn expand(s: &str, left: usize, right: usize) -> usize {
        let bytes = s.as_bytes();
        let (mut L, mut R): (isize, isize) = (left as isize, right as isize);
        while (L >= 0 && R < s.len() as isize && bytes[L as usize] == bytes[R as usize]) {
            L -= 1;
            R += 1;
        }
        (R-L-1) as usize
    }
}
