// Rust solution.

impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        if obstacle_grid.is_empty() { 0 }
        else {
            let (m, n) = (obstacle_grid.len(), obstacle_grid[0].len());
            let mut dp: Vec<i32> = vec![0; n];
            dp[0] = 1;
            for i in 0..m {
                dp[0] *= (1-obstacle_grid[i][0]);
                for j in 1..n {
                    dp[j] = (dp[j] + dp[j-1]) * (1-obstacle_grid[i][j]);
                }
            }
            dp[n-1]
        }
    }
}
