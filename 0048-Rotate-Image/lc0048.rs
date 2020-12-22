// Rust solution.

impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        matrix.reverse();
        Self::transpose(matrix);
    }

    pub fn transpose(matrix: &mut Vec<Vec<i32>>) {
        for i in 0..matrix.len() {
            for j in 0..i {
                // utilize copy trait here.
                let tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
}
