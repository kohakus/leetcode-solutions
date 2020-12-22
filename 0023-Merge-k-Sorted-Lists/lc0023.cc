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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) { return nullptr; }
    int length = lists.size();
    while (length > 1) {
      for (int i = 0; i < length/2; i++) {
        lists[i] = mergeTwoLists(lists[i], lists[length-1-i]);
      }
      length = (length+1) / 2;
    }
    return lists.front();
  }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
      return l2;
    } else if (l2 == nullptr) {
      return l1;
    } else {
      if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
      } else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
      }
    }
  }
};
