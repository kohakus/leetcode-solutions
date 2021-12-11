// Go solution.

// sliding window + hash method.
func lengthOfLongestSubstring(s string) int {
    poslog := map[byte]int{}
    start := 0
    ans := 0
    for i := 0; i < len(s); i++ {
        currChar := s[i]
        if prePos, ok := poslog[currChar]; ok {
            start = maxInt2(start, prePos+1)
        }
        ans = maxInt2(ans, i-start+1)
        poslog[currChar] = i
    }
    return ans
}

// implement max function for int type ...
func maxInt2(a, b int) int {
    if a > b {
        return a
    }
    return b
}