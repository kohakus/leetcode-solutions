# Python solution.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dumb = ListNode(0)
        dumb.next = head
        p1, p2 = dumb, dumb
        for i in range(n+1):
            p2 = p2.next
        while p2 != None:
            p1 = p1.next
            p2 = p2.next
        p1.next = p1.next.next
        return dumb.next
