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

// a concise method.
// Time complexity: O(N), Space complexity: O(1).
// 1. find the mid position of the list;
// 2. cut from the mid position, and reverse the second half;
// 3. merge two lists.
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) { return; }
        ListNode* slow = head;
        ListNode* fast = head->next;
        // find the mid position
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // cut from the mid position
        ListNode* head_half = slow->next;
        slow->next = nullptr;

        // reverse the second half
        // fast and slow variables are just reused here
        fast = head_half->next;
        head_half->next = nullptr;
        while (fast) {
            slow = fast->next;
            fast->next = head_half;
            head_half = fast;
            fast = slow;
        }

        // merge two lists
        ListNode* p1 = head;
        ListNode* p2 = head_half;
        while (p1) {
            ListNode* tmp = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = tmp;
        }
    }
};