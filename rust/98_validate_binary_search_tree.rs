use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    fn helper(min: Option<i32>, max: Option<i32>, node: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        match node {
            None => true,
            Some(n) => {
                let node = n.borrow();
                if (min.is_some() && node.val <= min.unwrap()) || (max.is_some() && node.val >= max.unwrap()) {
                    return false;
                }

                return Self::helper(min, Some(node.val), &node.left) && Self::helper(Some(node.val), max, &node.right);
            }
        }
    }

    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        return Self::helper(None, None, &root);
    }
}