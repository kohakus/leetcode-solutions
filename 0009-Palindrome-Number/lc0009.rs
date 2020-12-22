// Rust solution.

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if (x < 0 || (x%10 == 0 && x != 0)) { return false; }
        let mut revert: i32 = 0;
        let mut x: i32 = x;
        while (x > revert) {
            revert = revert * 10 + x % 10;
            x /= 10;
        }
        x == revert || x == revert/10
    }
}
