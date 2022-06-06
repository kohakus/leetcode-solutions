// Go solution.

// DP method
func numSquares(n int) int {
	dp := make([]int, n+1)
	dp[0] = 0
	for i := 1; i <= n; i++ {
		dp[i] = math.MaxInt32
		for j := 1; j*j <= i; j++ {
			dp[i] = minInt(dp[i], dp[i-j*j]+1)
		}
	}
	return dp[n]
}

func minInt(x, y int) int {
	if x > y {
		return y
	}
	return x
}