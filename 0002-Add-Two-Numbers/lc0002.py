# Python solution.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        acc = 0
        # create a dumb node as head
        head = ListNode(0)
        # curr_node is a mutable reference of head object
        curr_node = head
        while l1 or l2 or acc:
            if l1:
                acc += l1.val
                l1 = l1.next
            if l2:
                acc += l2.val
                l2 = l2.next
            curr_node.next = ListNode(acc%10)
            curr_node = curr_node.next
            acc = acc // 10
        return head.next
