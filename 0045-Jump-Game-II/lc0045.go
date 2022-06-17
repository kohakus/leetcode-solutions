// Go solution.

// DP method
func jump(nums []int) int {
    numLen := len(nums)

    // dp[i] means the result of jump(nums[:i+1])
    dp := make([]int, numLen)
    dp[0] = 0
    for i := 1; i < numLen; i++ {
        if i <= nums[0] {
            dp[i] = 1
        } else {
            dp[i] = math.MaxInt
        }
    }

    for i := nums[0] + 1; i < numLen; i++ {
        for j := 1; j <= i; j++ {
            if nums[i-j] >= j {
                dp[i] = minInt(dp[i], dp[i-j]+1)
            }
        }
    }
    return dp[numLen-1]
}

// Greedy method
func jump(nums []int) int {
    numLen := len(nums)
    if numLen < 2 {
        return 0
    }

    // expectPos means the farest position we can reach from the current perspective
    expectPos := nums[0]
    anchor := nums[0]
    steps := 0

    for i := 1; i < numLen; i++ {
        if i > anchor {
            steps++
            anchor = expectPos
        }
        expectPos = maxInt(expectPos, i+nums[i])
    }
    return steps + 1
}

func minInt(a, b int) int {
    if a > b {
        return b
    }
    return a
}

func maxInt(a, b int) int {
    if a > b {
        return a
    }
    return b
}