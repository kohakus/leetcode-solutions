// Go solution.

type TmpPoint struct {
    Val int
    Idx int
}

type TmpPointStack struct {
    Data []TmpPoint
}

func (stk *TmpPointStack) top() TmpPoint {
    return stk.Data[len(stk.Data)-1]
}

func (stk *TmpPointStack) topVal() int {
    return stk.Data[len(stk.Data)-1].Val
}

func (stk *TmpPointStack) topIdx() int {
    return stk.Data[len(stk.Data)-1].Idx
}

func (stk *TmpPointStack) push(ts TmpPoint) {
    stk.Data = append(stk.Data, ts)
}

func (stk *TmpPointStack) pop() {
    stk.Data = stk.Data[:len(stk.Data)-1]
}

func (stk *TmpPointStack) size() int {
    return len(stk.Data)
}

func dailyTemperatures(temperatures []int) []int {
    if temperatures == nil {
        return temperatures
    }

    lenIn := len(temperatures)
    ans := make([]int, lenIn)
    monoStack := &TmpPointStack{}

    for i := 0; i < lenIn; i++ {
        ithTmp := temperatures[i]

        for monoStack.size() > 0 && ithTmp > monoStack.topVal() {
            topItemIdx := monoStack.topIdx()
            ans[topItemIdx] = i - topItemIdx
            monoStack.pop()
        }
        monoStack.push(TmpPoint{ithTmp, i})
    }
    return ans
}