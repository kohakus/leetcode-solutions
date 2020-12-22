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
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut l1, mut l2) = (l1, l2);
        let mut dumb = Box::new(ListNode::new(0));
        let mut currNode = &mut dumb;

        while l1.is_some() && l2.is_some() {
            let v1 = l1.as_ref().unwrap().val;
            let v2 = l2.as_ref().unwrap().val;
            if v1 <= v2 {
                currNode.next = Some(Box::new(ListNode::new(v1)));
                currNode = currNode.next.as_mut().unwrap();
                l1 = l1.unwrap().next;
            } else {
                currNode.next = Some(Box::new(ListNode::new(v2)));
                currNode = currNode.next.as_mut().unwrap();
                l2 = l2.unwrap().next;
            }
        }

        currNode.next = match l1 {
            None => l2,
            _ => l1,
        };

        dumb.next
    }
}
