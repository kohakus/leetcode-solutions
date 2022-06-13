// Go solution.

// DP method
// f(i, j) = f(i-1, j) + f(i, j-1)
func uniquePaths(m int, n int) int {
    dp := make([][]int, m)
    for i := range dp {
        dp[i] = make([]int, n)
        dp[i][0] = 1
    }

    // initialization
    for j := range dp[0] {
        dp[0][j] = 1
    }

    for i := 1; i < m; i++ {
        for j := 1; j < n; j++ {
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
        }
    }
    return dp[m-1][n-1]
}

// DP method with O(N) space complexity
// f(i, j) = f(i-1, j) + f(i, j-1)
func uniquePaths(m int, n int) int {
    dp := make([]int, n)

    // initialization
    for j := 0; j < n; j++ {
        dp[j] = 1
    }

    for i := 1; i < m; i++ {
        for j := 1; j < n; j++ {
            dp[j] += dp[j-1]
        }
    }
    return dp[n-1]
}

// Combination | Binomial Theorem
func uniquePaths(m int, n int) int {
    // totally (m-1) + (n-1) steps
    totalSteps := m + n - 2

    // a possible choice
    // C(n, k) = C(n, n-k)
    kSteps := m
    if kSteps > n {
        kSteps = n
    }
    kSteps -= 1

    // C(n, 0) = 1
    ans := 1

    // C(n, k) = (n-k+1)/k * C(n, k-1)
    // C(n, 0) = 1
    for k := 1; k <= kSteps; k++ {
        // division must be placed last
        ans = (totalSteps - k + 1) * ans / k
    }
    return ans
}