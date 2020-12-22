// Rust solution.

impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<i32> = Vec::new();
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut candidates = candidates;
        candidates.sort();
        Self::backtrack(0, target, &candidates, &mut res, &mut ans);
        ans
    }

    pub fn backtrack(cur: usize,
                     target: i32,
                     candidates: &Vec<i32>,
                     res: &mut Vec<i32>,
                     ans: &mut Vec<Vec<i32>>) {
        if target == 0 {
            ans.push((*res).clone());
        } else {
            for i in cur..candidates.len() {
                if target >= candidates[i] {
                    res.push(candidates[i]);
                    Self::backtrack(i, target-candidates[i], candidates, res, ans);
                    res.pop();
                }
            }
        }
    }
}
