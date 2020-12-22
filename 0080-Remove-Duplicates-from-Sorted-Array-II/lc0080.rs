// Rust solution.

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut p = nums.len();
        if p > 2 {
            p = 2;
            for i in 2..nums.len() {
                if nums[i] != nums[p-2] {
                    nums[p] = nums[i];
                    p += 1;
                }
            }
        }
        p as i32
    }
}
