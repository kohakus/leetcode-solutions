// Rust solution.

use std::cmp::Ordering;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if !matrix.is_empty(){
            let (m, n) = (matrix.len(), matrix[0].len());
            let (mut lo, mut hi) = (0_usize, m*n);
            while lo < hi {
                let mid = (lo + hi) >> 1;
                match matrix[mid/n][mid%n].cmp(&target) {
                    Ordering::Less    => { lo = mid+1; },
                    Ordering::Greater => { hi = mid; },
                    Ordering::Equal   => { return true; },
                }
            }
        }
        false
    }
}
