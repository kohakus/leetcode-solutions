// JavaScript Solution.

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

var addTwoNumbers = function(l1, l2) {
    let acc = 0;
    // create dumb head node
    let head = new ListNode(0);
    let node = head;
    while(l1 !== null || l2 != null || acc > 0) {
        if (l1 !== null) {
            acc += l1.val;
            l1 = l1.next;
        }
        if (l2 !== null) {
            acc += l2.val;
            l2 = l2.next;
        }
        node.next = new ListNode(acc%10);
        node = node.next;
        acc = ~~(acc/10);
    }
    return head.next;
};
