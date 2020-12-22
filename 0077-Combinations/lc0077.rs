// Rust solution.

impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        if k == 0 {
            return vec![vec![]];
        }

        let mut ans: Vec<Vec<i32>> = Vec::new();
        for i in k..=n {
            // previous combine result will be moved here
            for mut pre in Self::combine(i-1, k-1) {
                pre.push(i);
                ans.push(pre);
            }
        }
        ans
    }
}
