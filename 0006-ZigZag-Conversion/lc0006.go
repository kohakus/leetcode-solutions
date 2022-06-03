// Go solution.

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}

	sLen := len(s)
	ret := make([]byte, 0, sLen)
	cycleLen := 2 * (numRows - 1)

	for i := 0; i < numRows; i++ {
		for j := 0; j+i < sLen; j += cycleLen {
			ret = append(ret, s[j+i])
			pos := j + cycleLen - i
			if i != 0 && i != numRows-1 && pos < sLen {
				ret = append(ret, s[pos])
			}
		}
	}
	return string(ret)
}