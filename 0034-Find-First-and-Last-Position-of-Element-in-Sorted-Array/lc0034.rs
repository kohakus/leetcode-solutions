// Rust solution.

impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        match nums[..] {
            [] => vec![-1, -1],
            _  => {
                let pos: usize = Solution::insert_pos(&nums, target);
                if pos < nums.len() && nums[pos] == target {
                    vec![pos as i32, (Solution::insert_pos(&nums, target+1)-1) as i32]
                } else {
                    vec![-1, -1]
                }
            }
        }
    }

    pub fn insert_pos(nums: &Vec<i32>, target: i32) -> usize {
        let (mut low, mut high) = (0_usize, nums.len());
        while low < high {
            let mid = low + ((high-low) >> 1);
            if nums[mid] >= target {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        low
    }
}

