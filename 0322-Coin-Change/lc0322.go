// Go solution.

// DP method
// f(i) means the fewest number of coins to make up amount i
// f(i) = min{f(i-c)}+1 where c in coins
func coinChange(coins []int, amount int) int {
    dp := make([]int, amount+1)
    for i := 1; i <= amount; i++ {
        dp[i] = math.MaxInt32
    }
    for _, c := range coins {
        for i := c; i <= amount; i++ {
            dp[i] = minInt(dp[i], dp[i-c]+1)
        }
    }
    if dp[amount] > amount {
        // no combination match
        return -1
    }
    return dp[amount]
}

func minInt(a, b int) int {
    if a > b {
        return b
    }
    return a
}