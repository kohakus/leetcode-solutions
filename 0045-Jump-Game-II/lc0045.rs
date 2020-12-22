// Rust solution.

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n < 2 { return 0; }
        let (mut expect, mut anchor) = (nums[0], nums[0]);
        let mut step = 0;
        for i in 1..n {
            if i > anchor as usize {
                anchor = expect;
                step += 1;
            }
            expect = std::cmp::max(expect, i as i32 + nums[i]);
        }
        step+1
    }
}
