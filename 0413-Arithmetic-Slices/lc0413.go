// Go solution.

// DP method
func numberOfArithmeticSlices(nums []int) int {
    numsLen := len(nums)
    if numsLen < 3 {
        return 0
    }

    dp := make([]int, numsLen)
    ans := 0
    for i := 2; i < numsLen; i++ {
        if nums[i]-nums[i-1] == nums[i-1]-nums[i-2] {
            dp[i] = dp[i-1] + 1
        }
        ans += dp[i]
    }
    return ans
}

// DP method with O(1) space complexity
func numberOfArithmeticSlices(nums []int) int {
    numsLen := len(nums)
    if numsLen < 3 {
        return 0
    }

    cnt := 0
    ans := 0
    for i := 2; i < numsLen; i++ {
        if nums[i]-nums[i-1] == nums[i-1]-nums[i-2] {
            cnt++
        } else {
            cnt = 0
        }
        ans += cnt
    }
    return ans
}