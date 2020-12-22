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
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dumb = Some(Box::new(ListNode {val: 0, next: head}));
        let mut length = 0;
        {
            let mut p = dumb.as_ref();
            while p.unwrap().next.is_some() {
                p = p.unwrap().next.as_ref();
                length += 1;
            }
        }
        let mut p = dumb.as_mut();
        for _ in 0..(length-n) {
            p = p.unwrap().next.as_mut();
        }
        p.unwrap().next = p.as_mut().unwrap().next.as_mut().unwrap().next.take();
        dumb.unwrap().next
    }
}
