// Rust solution.

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut expect = 0_i32;
        for i in 0..nums.len() {
            if (i > expect as usize) { return false; }
            expect = std::cmp::max(expect, i as i32 + nums[i]);
        }
        true
    }
}
