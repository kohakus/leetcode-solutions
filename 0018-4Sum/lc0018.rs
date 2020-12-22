// Rust solution.

struct Bcparam<'a> {
    nums: &'a [i32],
    ans: Vec<Vec<i32>>,
    res: Vec<i32>,
}

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        Solution::N_sum(nums, target, 4)
    }

    pub fn N_sum(mut nums: Vec<i32>, target: i32, n: usize) -> Vec<Vec<i32>> {
        nums.sort();
        let mut params = Bcparam {
            nums: &nums,
            ans: Vec::new(),
            res: vec![0; n],
        };
        Solution::N_solve(&mut params, target, n, 0, 0);
        params.ans
    }

    pub fn N_solve(params: &mut Bcparam, target: i32, n: usize, idx: usize, cursor: usize) {
        let nums: &[i32] = params.nums;
        let sz: usize = nums.len() - idx;
        if sz < n { return; }
        if n == 2 {
            let (mut left, mut right) = (idx, idx+sz-1);
            while left < right {
                let sumtwo = nums[left] + nums[right];
                if sumtwo == target {
                    params.res[cursor] = nums[left];
                    params.res[cursor+1] = nums[right];
                    params.ans.push(params.res.clone());
                    while (left < right && nums[left] == nums[left+1]) { left += 1; }
                    while (left < right && nums[right] == nums[right-1]) { right -= 1; }
                    left += 1; right -= 1;
                } else if sumtwo < target {
                    left += 1;
                } else { right -= 1; }
            }
        } else {
            for i in idx..(nums.len()-n+1) {
                if i > idx && nums[i] == nums[i-1] { continue; }
                params.res[cursor] = nums[i];
                Solution::N_solve(params, target-nums[i], n-1, i+1, cursor+1);
            }
        }
    }
}
