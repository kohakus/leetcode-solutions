// Rust solution.

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hash = HashMap::new();
        for (k, v) in nums.iter().enumerate() {
            match hash.get(&(target - v)) {
                Some(&searched_idx) => return vec![searched_idx as i32, k as i32],
                _ => { hash.insert(v, k); }
            }
        }
        vec![]
    }
}
