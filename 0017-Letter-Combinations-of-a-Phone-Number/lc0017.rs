// Rust solution.

struct Bcparam<'a> {
    digits: &'a str,
    ans: Vec<String>,
    res: Vec<char>,
}

impl<'a> Bcparam<'a> {
    #[inline]
    pub fn dig() -> Vec<&'static str> {
        vec!["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    }
}

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let sz = digits.len();
        if (sz <= 0) { return vec![]; }
        let mut params = Bcparam {
            digits: &digits[..],
            ans: Vec::new(),
            res: vec!['0'; sz],
        };
        Solution::backtracking(0, sz, &mut params);
        params.ans
    }

    pub fn backtracking(depth: usize, sz: usize, params: &mut Bcparam) {
        if depth == sz {
            params.ans.push(params.res.iter().collect::<String>());
            return;
        }

        let button = (params.digits.as_bytes()[depth] as char).to_digit(10).unwrap();
        for letter in Bcparam::dig()[button as usize].chars() {
            params.res[depth] = letter;
            Solution::backtracking(depth+1, sz, params);
        }
    }
}
