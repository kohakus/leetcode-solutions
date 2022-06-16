// Go solution.

// Greedy method
func convertTime(current string, correct string) int {
    diffMinutes := getDiffMinutes(current, correct)
    cnt := 0
    for _, incVal := range []int{60, 15, 5} {
        cnt += diffMinutes / incVal
        diffMinutes %= incVal
    }
    return cnt + diffMinutes
}

func getDiffMinutes(current string, correct string) int {
    curHour, _ := strconv.Atoi(current[:2])
    targetHour, _ := strconv.Atoi(correct[:2])
    curMinutes, _ := strconv.Atoi(current[3:])
    targetMinutes, _ := strconv.Atoi(correct[3:])

    // the input constraint guarantee that current <= correct
    return (targetHour-curHour)*60 - curMinutes + targetMinutes
}