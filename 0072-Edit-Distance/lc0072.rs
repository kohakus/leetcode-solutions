// Rust solution.

impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let (m, n) = (word1.len(), word2.len());
        let mut dp: Vec<i32> = (0_i32..=n as i32).collect();
        let mut pre = 0_i32;

        for (i, c1) in word1.chars().enumerate() {
            pre = dp[0];
            dp[0] = 1 + i as i32;
            for (j, c2) in word2.chars().enumerate() {
                let temp = dp[j+1];
                if c1 == c2 {
                    dp[j+1] = pre;
                } else {
                    dp[j+1] = dp[j+1].min(dp[j]).min(pre) + 1;
                }
                pre = temp;
            }
        }
        dp[n]
    }
}
