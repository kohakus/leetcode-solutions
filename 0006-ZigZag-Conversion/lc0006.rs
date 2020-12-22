// Rust solution.

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if (num_rows == 1) { return s; }
        let mut ret: Vec<String> = vec![String::new(); num_rows as usize];
        let mut row_cursor: usize = 0;
        let mut trigger = false;

        for c in s.chars() {
            ret[row_cursor].push(c);
            row_cursor = match trigger {
                false => row_cursor+1,
                true => row_cursor-1,
            };
            if (row_cursor == 0 || row_cursor as i32 == num_rows-1) {
                trigger = !trigger;
            }
        }
        ret.join("")
    }
}
