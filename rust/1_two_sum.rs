use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::with_capacity(nums.len());

        for (i, &num) in nums.iter().enumerate() {
            let complement: i32 = target - num;
            if let Some(&stored_index) = map.get(&complement) {
                return vec![stored_index, i as i32];
            }

            map.insert(num, i as i32);
        }

        vec![]
    }
}