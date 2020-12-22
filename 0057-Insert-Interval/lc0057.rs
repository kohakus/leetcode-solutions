// Rust solution.

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let (mut start, mut end) = (new_interval[0], new_interval[1]);
        let mut lstl: Vec<Vec<i32>> = Vec::new();
        let mut lstr: Vec<Vec<i32>> = Vec::new();

        for interval in intervals.into_iter() {
            let (left, right) = (interval[0], interval[1]);
            if start > right {
                lstl.push(interval);
            } else if end < left {
                lstr.push(interval);
            } else {
                start = start.min(left);
                end = end.max(right);
            }
        }

        lstl.push(vec![start, end]);
        lstl.extend(lstr);
        lstl
    }
}
