// Rust solution.

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.is_empty() { return "".to_string(); }
        let strvec = strs.iter().map(|s| s.as_bytes()).collect::<Vec<_>>();
        for (k, &c) in strvec[0].iter().enumerate() {
            for idx in 1..strs.len() {
                if k == strs[idx].len() || c != strvec[idx][k] {
                    return String::from(&strs[0][0..k]);
                }
            }
        }
        return String::from(&strs[0][..]);
    }
}
