// C++ solution.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy = ListNode(-1);
    dummy.next = head;
    ListNode* pre = &dummy;
    for (int i = 0; i < m-1; i++) {
      pre = pre->next;
    }

    ListNode* snode = pre->next;
    for (int i = 0; i < n-m; i++) {
      ListNode* tmp = pre->next;
      pre->next = snode->next;
      snode-> next = snode->next->next;
      pre->next->next = tmp;
    }

    return dummy.next;
  }
};
