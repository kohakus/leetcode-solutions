// Rust solution.

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ans: Vec<String> = vec![];
        Solution::generate(n, 0, 0, "".to_string(), &mut ans);
        ans
    }

    pub fn generate(n: i32, left: i32, right: i32, s: String, ans: &mut Vec<String>) {
        if right == n {
            ans.push(s.clone());
        }
        if left < n {
            Solution::generate(n, left+1, right, s.clone()+"(", ans);
        }
        if right < left {
            Solution::generate(n, left, right+1, s.clone()+")", ans);
        }
    }
}
