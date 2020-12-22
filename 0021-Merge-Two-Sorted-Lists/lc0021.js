// JavaScript solution.

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

var mergeTwoLists = function(l1, l2) {
    let dumb = new ListNode(0);
    let curr = dumb;

    while (l1 !== null && l2 !== null) {
        if (l1.val <= l2.val) {
            curr.next = new ListNode(l1.val);
            curr = curr.next;
            l1 = l1.next;
        } else {
            curr.next = new ListNode(l2.val);
            curr = curr.next;
            l2 = l2.next;
        }
    }

    curr.next = l1 !== null? l1 : l2;
    return dumb.next;
};
