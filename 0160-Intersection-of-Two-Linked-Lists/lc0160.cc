// C++ solution.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Hash Table.
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> logger;
        while (headA) {
            logger.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (logger.find(headB) != logger.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

// Two pointers.
// len(A) + len(B) == len(B) + len(A).
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* lst_a = headA;
        ListNode* lst_b = headB;
        while (lst_a != lst_b) {
            lst_a = lst_a == nullptr ? headB : lst_a->next;
            lst_b = lst_b == nullptr ? headA : lst_b->next;
        }
        return lst_a;
    }
};