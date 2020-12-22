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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* oddp = head;
        ListNode* evenp = head->next;
        ListNode* even_head = evenp;

        while (evenp && evenp->next) {
            oddp->next = evenp->next;
            oddp = oddp->next;
            evenp->next = oddp->next;
            evenp = evenp->next;
        }
        oddp->next = even_head;
        return head;
    }
};