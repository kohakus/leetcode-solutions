// Go solution.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dumb := ListNode{}
    acc := 0
    p, p1, p2 := &dumb, l1, l2

    // merge two lists
    for p1 != nil || p2 != nil || acc > 0 {
        if p1 != nil {
            acc += p1.Val
            p1 = p1.Next
        }
        if p2 != nil {
            acc += p2.Val
            p2 = p2.Next
        }
        p.Next = &ListNode{Val: acc % 10}
        p = p.Next
        acc /= 10
    }
    return dumb.Next
}