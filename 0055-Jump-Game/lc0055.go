// Go solution.

// DP method
func canJump(nums []int) bool {
    if nums == nil {
        return true
    }

    numLen := len(nums)
    if numLen <= 1 || nums[0] >= numLen-1 {
        return true
    }

    // dp[i] means the result of canJump(nums[:i+1])
    dp := make([]bool, len(nums))

    for i := 0; i <= nums[0] && i < numLen; i++ {
        dp[i] = true
    }

    for i := nums[0] + 1; i < numLen; i++ {
        for j := 1; j <= i; j++ {
            if dp[i-j] && nums[i-j] >= j {
                dp[i] = true
                break
            }
        }
    }
    return dp[numLen-1]
}

// Greedy method
func canJump(nums []int) bool {
    expectPos := 0
    for i := 0; i < len(nums); i++ {
        if i > expectPos {
            return false
        }
        expectPos = maxInt(expectPos, i+nums[i])
    }
    return true
}

func maxInt(a, b int) int {
    if a > b {
        return a
    }
    return b
}