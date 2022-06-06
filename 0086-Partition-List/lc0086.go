// Go solution.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	leftDummy := &ListNode{}
	rightDummy := &ListNode{}
	left := leftDummy
	right := rightDummy
	curr := head

	for curr != nil {
		if curr.Val < x {
			left.Next = curr
			left = left.Next
		} else {
			right.Next = curr
			right = right.Next
		}
		curr = curr.Next
	}

	right.Next = nil
	left.Next = rightDummy.Next
	return leftDummy.Next
}