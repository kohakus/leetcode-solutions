// Rust solution.

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let mut dp = vec![vec![false; p.len()+1]; s.len()+1];
        dp[s.len()][p.len()] = true;
        let s = s.into_bytes();
        let p = p.into_bytes();

        for i in (0..s.len()+1).rev() {
            for j in (0..p.len()).rev() {
                let firstMatch: bool = (i < s.len()) && (s[i] == p[j] || p[j] as char == '.');
                if (j+1 < p.len() && p[j+1] as char == '*') {
                    dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }
        dp[0][0]
    }
}
