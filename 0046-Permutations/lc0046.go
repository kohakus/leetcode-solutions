// Go solution.

type dfsRecord struct {
	ans  *[][]int
	used []bool
}

func permute(nums []int) [][]int {
	totalCnt := len(nums)
	record := &dfsRecord{
		ans:  &[][]int{},
		used: make([]bool, totalCnt),
	}
	currRes := make([]int, totalCnt)
	backtrack(nums, record, &currRes, 0)
	return *record.ans
}

func backtrack(nums []int, record *dfsRecord, currResPtr *[]int, currStep int) {
	if currStep == len(nums) {
		*record.ans = append(*record.ans, append([]int{}, *currResPtr...))
		return
	}
	for i := 0; i < len(nums); i++ {
		if !record.used[i] {
			record.used[i] = true
			(*currResPtr)[currStep] = nums[i]
			backtrack(nums, record, currResPtr, currStep+1)
			record.used[i] = false
		}
	}
}