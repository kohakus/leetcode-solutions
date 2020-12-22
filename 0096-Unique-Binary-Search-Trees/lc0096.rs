// Rust solution.

impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let n: i64 = n as i64;
        let mut ans = 1_i64;
        for k in 1..=n {
            ans = ans * (2*n - k + 1) / k;
        }
        (ans / (n+1)) as i32
    }
}