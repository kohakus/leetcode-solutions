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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) { return head; }
        ListNode dumb(-1);
        dumb.next = head;
        ListNode* cur = dumb.next;
        int len = 0;
        while (cur) {
            len++;
            cur = cur->next;
        }
        ListNode* pre = &dumb;
        ListNode* next;
        while (len >= k) {
            cur = pre->next;
            next = cur->next;
            // reverse a k-group
            for (int i = 0; i < k-1; i++) {
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }
            pre = cur;
            len -= k;
        }
        return dumb.next;
    }
};