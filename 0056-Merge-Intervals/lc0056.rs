// Rust solution.

impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut intervals = intervals;
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));
        for (k, v) in intervals.into_iter().enumerate() {
            if k == 0 { ans.push(v); }
            else {
                if let Some(back) = ans.last_mut() {
                    if v[0] > back[1] {
                        ans.push(v);
                    } else {
                        back[1] = std::cmp::max(back[1], v[1]);
                    }
                }
            }
        }
        ans
    }
}
