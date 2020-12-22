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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dumb(-1);
        ListNode* cur = &dumb;
        int acc = 0;
        while (l1 || l2 || acc > 0) {
            if (l1) {
                acc += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                acc += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(acc % 10);
            cur = cur->next;
            acc /= 10;
        }
        return dumb.next;
    }
};