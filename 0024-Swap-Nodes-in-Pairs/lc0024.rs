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
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = head;
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        } else {
            let mut temp = head.as_mut().unwrap().next.take();
            head.as_mut().unwrap().next = Self::swap_pairs(temp.as_mut().unwrap().next.take());
            temp.as_mut().unwrap().next = head;
            temp
        }
    }
}
