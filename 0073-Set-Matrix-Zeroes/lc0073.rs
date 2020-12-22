// Rust solution.

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let (m, n) = (matrix.len(), matrix[0].len());
        let mut scol0: bool = false;

        for i in 0..m {
            if matrix[i][0] == 0 {
                scol0 = true;
                break;
            }
        }

        for i in 0..m {
            for j in 1..n {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for i in (0..m).rev() {
            for j in (1..n).rev() {
                if matrix[i][0] == 0 || matrix[0][j] == 0 {
                    matrix[i][j] = 0;
                }
            }
            if scol0 { matrix[i][0] = 0; }
        }
    }
}
