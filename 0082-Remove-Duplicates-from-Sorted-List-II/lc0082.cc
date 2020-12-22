// C++ solution.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode dummy = ListNode(head->val - 1, head);
    ListNode *pre = &dummy, *cur = head;

    while (cur != nullptr) {
      int tmp = cur->val;
      if (cur->next != nullptr && tmp == cur->next->val) {
        while (cur != nullptr && tmp == cur->val) {
          cur = cur->next;
        }
        pre->next = cur;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }

    return dummy.next;
  }
};