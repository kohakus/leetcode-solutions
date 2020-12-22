// Go solution.

func twoSum(nums []int, target int) []int {
    hash := make(map[int]int)
    for idx, num := range nums {
        _, exist := hash[num]
        if exist {
            return []int{hash[num], idx}
        } else {
            hash[target-num] = idx
        }
    }
    return nil
}