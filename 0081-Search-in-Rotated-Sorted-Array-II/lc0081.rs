// Rust solution.

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        if !nums.is_empty() {
            let mut head: usize = 0;
            let n: usize = nums.len();
            while head < n-1 && nums[head] == nums[n-1] {
                head += 1;
            }

            let (mut low, mut high) = (head, n);
            while low < high {
                let mid = (low + high) >> 1;
                if nums[mid] == target {
                    return true;
                } else if !((nums[head] <= target) ^ (nums[head] > nums[mid]) ^ (nums[mid] > target)) {
                    high = mid;
                } else {
                    low = mid+1;
                }
            }
        }
        false
    }
}
