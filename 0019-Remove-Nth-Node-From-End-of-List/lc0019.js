// JavaScript solution.

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */

var removeNthFromEnd = function(head, n) {
    let dumb = new ListNode(0);
    dumb.next = head;
    let p1 = dumb;
    let p2 = dumb;
    for (let i = 0; i < n+1; i++) {
        p2 = p2.next;
    }
    while (p2 !== null) {
        p1 = p1.next;
        p2 = p2.next;
    }
    p1.next = p1.next.next;
    return dumb.next;
};
