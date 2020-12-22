// Rust solution.

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        if grid.is_empty() { 0 }
        else {
            let (m, n) = (grid.len(), grid[0].len());
            let mut dp: Vec<i32> = vec![std::i32::MAX; n];
            dp[0] = 0;
            for i in 0..m {
                dp[0] += grid[i][0];
                for j in 1..n {
                    dp[j] = dp[j-1].min(dp[j]) + grid[i][j];
                }
            }
            dp[n-1]
        }
    }
}
