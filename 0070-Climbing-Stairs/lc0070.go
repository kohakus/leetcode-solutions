// Go solution.

// DP method
func climbStairs(n int) int {
    // dp[i] means the result of climbStairs(i)
    dp := make([]int, n+1)
    dp[0] = 1
    dp[1] = 1

    for i := 2; i <= n; i++ {
        dp[i] = dp[i-1] + dp[i-2]
    }
    return dp[n]
}

// DP method with O(1) space complexity
func climbStairs(n int) int {
    s0 := 1
    s1 := 1
    for i := 2; i <= n; i++ {
        s1 = s1 + s0
        s0 = s1 - s0
    }
    return s1
}

// Cassini Identity + Fast Pow
// O(logN) time complexity
func climbStairs(n int) int {
    res := []int{1, 0, 0, 1}
    tmp := []int{1, 1, 1, 0}
    for ; n != 0; n >>= 1 {
        if n&1 == 1 {
            matProd(res, tmp)
        }
        if n > 1 {
            matProd(tmp, tmp)
        }
    }
    return res[0]
}

func matProd(l, r []int) {
    a := l[0]*r[0] + l[1]*r[2]
    b := l[0]*r[1] + l[1]*r[3]
    c := l[2]*r[0] + l[3]*r[2]
    d := l[2]*r[1] + l[3]*r[3]
    l[0], l[1], l[2], l[3] = a, b, c, d
}