// Rust solution.

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ret: Vec<Vec<i32>> = Vec::new();
        let mut nums = nums;
        if (nums.len() < 3) {
            return ret;
        } else {
            nums.sort();
        }

        for i in 0..(nums.len()-2) {
            if (i > 0 && nums[i] == nums[i-1]) { continue; }
            let (mut left, mut right) = (i+1, nums.len()-1);
            while (left < right) {
                let sumthree = nums[left] + nums[right] + nums[i];
                match sumthree {
                    _ if sumthree == 0 => {
                        ret.push(vec![nums[i], nums[left], nums[right]]);
                        while (left < right && nums[left] == nums[left+1]) { left += 1; }
                        while (left < right && nums[right] == nums[right-1]) { right -= 1; }
                        left += 1; right -= 1;
                    },
                    _ if sumthree < 0 => { left += 1; },
                    _ => { right -= 1; }
                }
            }
        }
        ret
    }
}
