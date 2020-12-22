// C++ solution.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Tortoise and the hare algorithm
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; fast != nullptr; i++){
            fast = fast->next;
            if (i&1) { slow = slow->next; }
            if (fast == slow) { return true; }
        }
        return false;
    }
};