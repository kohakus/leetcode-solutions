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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dumb(0);
        dumb.next = head;
        ListNode* p1 = &dumb;
        ListNode* p2 = &dumb;
        while ((n--) >= 0) p2 = p2 -> next;
        while (p2 != nullptr) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        p1 -> next = p1 -> next -> next;
        return dumb.next;
    }
};