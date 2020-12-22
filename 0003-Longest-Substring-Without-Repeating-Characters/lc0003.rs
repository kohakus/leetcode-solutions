// Rust solution.

use std::collections::HashMap;
use std::cmp;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut poslog: HashMap<char, usize> = HashMap::new();
        let (mut start, mut ans): (usize, usize) = (0, 0);
        for (cursor, val) in s.chars().enumerate() {
            start = cmp::max(start, *poslog.get(&val).unwrap_or(&0));
            ans = cmp::max(ans, cursor-start+1);
            poslog.insert(val, cursor+1);
        }
        ans as i32
    }
}
