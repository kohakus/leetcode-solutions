# Python solution.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dumb = ListNode(0)
        end = dumb

        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                end.next = ListNode(l1.val)
                end = end.next
                l1 = l1.next
            else:
                end.next = ListNode(l2.val)
                end = end.next
                l2 = l2.next

        end.next = l1 if l1 != None else l2
        return dumb.next
