// Rust solution.

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut ans = std::i32::MIN;
        if !nums.is_empty() {
            let mut dpval = nums[0];
            ans = nums[0];
            for i in 1..nums.len() {
                dpval = std::cmp::max(nums[i], dpval+nums[i]);
                ans = std::cmp::max(ans, dpval);
            }
        }
        ans
    }
}
