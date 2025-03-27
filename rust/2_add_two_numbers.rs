
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}

impl Solution {
    fn helper(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, carry: &mut i32) -> Option<Box<ListNode>>
    {
        if *carry == 0 && l1.is_none() && l2.is_none() {
            return None;
        }

        let a = match l1 {
            Some(T) => *T,
            None    => ListNode::new(0),
        };

        let b = match l2 {
            Some(T) => *T,
            None    => ListNode::new(0),
        };

        let val: i32 = a.val + b.val + *carry;
        let mut node: ListNode = ListNode::new(val%10);
        *carry = val / 10;
        node.next = Self::helper(a.next, b.next, carry);

        return Some(Box::new(node));
    }

    pub fn add_two_numbers(l1: Option<Box<ListNode>>,
                           l2: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        let mut carry = 0;
        return Self::helper(l1, l2, &mut carry);
    }

}