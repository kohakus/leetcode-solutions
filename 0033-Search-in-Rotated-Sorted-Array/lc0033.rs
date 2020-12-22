// Rust solution.

use std::cmp::Ordering;
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let adjust = |x: i32| -> i32 {
            match (target < nums[0]) {
                true => if x < nums[0] { x } else { std::i32::MIN },
                false => if x < nums[0] { std::i32::MAX } else { x },
            }
        };

        let (mut low, mut high) = (0_usize, nums.len());
        while low < high {
            let mid = (low + high) >> 1;
            match adjust(nums[mid]).cmp(&target) {
                Ordering::Less => { low = mid+1; },
                Ordering::Greater => { high = mid },
                Ordering::Equal => { return mid as i32; }
            }
        }
        -1
    }
}
