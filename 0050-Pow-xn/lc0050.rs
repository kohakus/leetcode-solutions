// Rust solution.

impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        match n {
            std::i32::MIN => Self::my_pow(1_f64/x, -(n+1)) / x,
            _ if n < 0 => Self::my_pow(1_f64/x, -n),
            _ => {
                let mut res: f64 = 1.0;
                let (mut x, mut n) = (x, n);
                while n > 0 {
                    if n&1 == 1 { res *= x; }
                    x *= x;
                    n = n >> 1;
                }
                res
            }
        }
    }
}
