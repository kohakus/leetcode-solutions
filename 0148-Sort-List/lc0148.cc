// C++ solution.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// simple top-down merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return head; }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dumb(0);
        ListNode* cur = &dumb;

        for (; l1 != nullptr && l2 != nullptr; cur = cur->next) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
        }

        if (l1 != nullptr) {
            cur->next = l1;
        } else {
            cur->next = l2;
        }

        return dumb.next;
    }
};