// Rust solution.

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut st: Vec<char> = Vec::new();
        let rpar: [char; 3] = [')', '}', ']'];
        let lpar: [char; 3] = ['(', '{', '['];

        for c in s.chars() {
            let mut rmatched = false;
            for i in 0..3 {
                if c == rpar[i] {
                    match st.pop() {
                        Some(top) => {
                            if top != lpar[i] {
                                return false;
                            } else {
                                rmatched = true;
                            }
                        },
                        None => { return false; }
                    }
                }
            }
            if !rmatched { st.push(c); }
        }
        st.is_empty()
    }
}
