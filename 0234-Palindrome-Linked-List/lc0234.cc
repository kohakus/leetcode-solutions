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

// inplace check
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) { return true; }

        ListNode* left_end = listMid(head);
        ListNode* left_begin = head;
        ListNode* right_begin = listReverse(left_end->next);
        bool check_res = true;
        for (; check_res && right_begin != nullptr; ) {
            if (left_begin->val != right_begin->val) {
                check_res = false;
            }
            left_begin = left_begin->next;
            right_begin = right_begin->next;
        }
        return check_res;
    }

    ListNode* listMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int list_size = 0;
        for (; fast != nullptr && fast->next != nullptr; list_size++) {
            fast = fast->next;
            if (list_size & 1) {
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* listReverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};
