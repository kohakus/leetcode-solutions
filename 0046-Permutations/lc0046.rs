// Rust solution.

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut res: Vec<i32> = Vec::new();
        let mut used = vec![false; nums.len()];
        Self::backtrack(&nums, &mut res, &mut used, &mut ans);
        ans
    }

    pub fn backtrack(nums: &Vec<i32>, res: &mut Vec<i32>,
                     used: &mut Vec<bool>, ans: &mut Vec<Vec<i32>>) -> () {
        if res.len() == nums.len() {
            ans.push(res.clone());
        } else {
            for i in 0..nums.len() {
                if !used[i] {
                    res.push(nums[i]);
                    used[i] = true;
                    Self::backtrack(nums, res, used, ans);
                    res.pop();
                    used[i] = false;
                }
            }
        }
    }
}
