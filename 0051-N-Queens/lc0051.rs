// Rust solution.

impl Solution {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let mut ans: Vec<Vec<String>> = Vec::new();
        let mut res: Vec<usize> = vec![0; n as usize];
        Self::solve(0, &mut res, &mut ans);
        ans
    }

    pub fn solve(cur: usize, res: &mut Vec<usize>, ans: &mut Vec<Vec<String>>) {
        let n = res.len();
        if (cur == n) {
            let mut checkboard: Vec<String> = Vec::new();
            for i in 0..n {
                let line = format!("{}Q{}", ".".repeat(res[i]), ".".repeat(n-res[i]-1));
                checkboard.push(line)
            }
            ans.push(checkboard);
        }
        for i in 0..n {
            let mut state: bool = true;
            for j in 0..cur {
                if i == res[j] || cur-i == j-res[j] || cur+i == j+res[j] {
                    state = false;
                    break;
                }
            }
            if state {
                res[cur] = i;
                Self::solve(cur+1, res, ans);
            }
        }
    }
}
