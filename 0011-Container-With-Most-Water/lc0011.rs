// Rust solution.

use std::cmp;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut left, mut right): (usize, usize) = (0, height.len()-1);
        let mut ret: i32 = 0;
        while left < right {
            ret = cmp::max(ret, cmp::min(height[left], height[right]) * (right-left) as i32);
            match height[left] {
                _ if height[left] < height[right] => { left += 1; },
                _ => { right -= 1; },
            }
        }
        ret
    }
}
