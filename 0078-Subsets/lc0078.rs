// Rust solution.

impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n: usize = 1 << nums.len();
        let mut ans: Vec<Vec<i32>> = vec![vec![]; n];
        for i in 0..n {
            for p in 0..nums.len() {
                if (i >> p) & 1 == 1 {
                    ans[i].push(nums[p]);
                }
            }
        }
        ans
    }
}
