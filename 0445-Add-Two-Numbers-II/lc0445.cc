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

// use stacks.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while (l1 != nullptr) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* cur = nullptr;
        ListNode* pre = nullptr;
        int acc = 0;
        while (!st1.empty() || !st2.empty() || acc) {
            if (!st1.empty()) {
                acc += st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                acc += st2.top();
                st2.pop();
            }

            pre = new ListNode(acc % 10);
            pre->next = cur;
            cur = pre;
            acc /= 10;
        }
        return cur;
    }
};