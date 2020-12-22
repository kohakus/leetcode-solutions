// Rust solution.

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>,
                           l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut l1, mut l2) = (l1, l2);
        let mut acc = 0;
        // create a dumb node as list head
        let mut head = Box::new(ListNode::new(0));
        let mut curr_node = &mut head;

        while (l1.is_some() || l2.is_some() || acc > 0) {
            acc = acc + match l1 {
                Some(node) => {
                    l1 = node.next;
                    node.val
                },
                _ => 0
            };
            acc = acc + match l2 {
                Some(node) => {
                    l2 = node.next;
                    node.val
                },
                _ => 0
            };
            curr_node.next = Some(Box::new(ListNode::new(acc%10)));
            curr_node = curr_node.next.as_mut().unwrap();
            acc = acc / 10;
        }
        head.next
    }
}
