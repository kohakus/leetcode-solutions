// Go solution.

// DP method
func minimumTotal(triangle [][]int) int {
    tHeight := len(triangle)
    dp := make([]int, len(triangle[tHeight-1]))
    copy(dp, triangle[tHeight-1])

    // bottom-up iteration
    for i := tHeight - 2; i >= 0; i-- {
        for j := 0; j <= i; j++ {
            dp[j] = minInt(dp[j], dp[j+1]) + triangle[i][j]
        }
    }

    return dp[0]
}

func minInt(a, b int) int {
    if a > b {
        return b
    }
    return a
}