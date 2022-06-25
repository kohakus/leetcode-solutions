// Go solution.

// Sequence monotonicity
// The problem requires that every number has to be equal or greater than previous number.
// 1. Make the previous number smaller or equal to current number (if nums[i-2] is not greater than nums[i])
// 2. Make the current number equal to previous number (if 1. cannot be executed)
func checkPossibility(nums []int) bool {
    isModified := false
    numsLen := len(nums)
    for i := 1; i < numsLen; i++ {
        if nums[i] < nums[i-1] {
            if isModified {
                return false
            }
            isModified = true
            if i-2 >= 0 && nums[i-2] > nums[i] {
                nums[i] = nums[i-1]
            }
        }
    }
    return true
}