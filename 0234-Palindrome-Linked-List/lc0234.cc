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

// check it recursively
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }
private:
    bool check(ListNode*& pl, ListNode* pr) {
        if (pr == nullptr) { return true; }
        if (check(pl, pr->next)) {
            if (pl->val == pr->val) {
                pl = pl->next;
                return true;
            }
        }
        return false;
    }
};