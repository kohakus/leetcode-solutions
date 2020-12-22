// Rust solution.
// Dutch national flag problem

use std::cmp::Ordering;

impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let (mut l, mut m, mut h) = (0_usize, 0_usize, nums.len());
        match h {
            0 | 1 => { return; },
            _ => { h -= 1; },
        }
        while m <= h && h > 0 {
            match nums[m].cmp(&1) {
                Ordering::Less => {
                    nums.swap(l, m);
                    l += 1;
                    m += 1;
                },
                Ordering::Greater => {
                    nums.swap(m, h);
                    h -= 1;
                },
                _ => { m += 1; },
            }
        }
    }
}
