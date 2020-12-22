// Rust solution.

impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums;
        let sz = nums.len();
        let (mut bestMatch, mut minDiff): (i32, i32) = (0, std::i32::MAX);
        if (sz < 3) { return -1; }
        else { nums.sort(); }

        for i in 0..(sz-2) {
            if (i > 0 && nums[i] == nums[i-1]) { continue; }
            let (mut left, mut right) = (i+1, sz-1);
            while (left < right) {
                let sum = nums[i] + nums[left] + nums[right];
                let diff = (sum-target).abs();
                if (diff == 0) { return target; }
                if (diff < minDiff) {
                    minDiff = diff;
                    bestMatch = sum;
                }
                if (sum > target) {
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }
        bestMatch
    }
}
