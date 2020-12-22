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

// just construct two lists and concat them together.
// we can directly use the original data without copy.
// Time complexity: O(N), Space complexity: O(1).
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dumb(0);
        ListNode right_dumb(0);
        ListNode* left = &left_dumb;
        ListNode* right = &right_dumb;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                left->next = cur;
                left = left->next;
            } else {
                right->next = cur;
                right = right->next;
            }
            cur = cur->next;
        }
        right->next = nullptr;
        left->next = right_dumb.next;
        return left_dumb.next;
    }
};