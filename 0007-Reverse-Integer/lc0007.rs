// Rust solution.

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut ret: i32 = 0;
        let mut xt: i32 = x;
        while (xt != 0) {
            let pop = xt % 10;
            xt /= 10;
            if (ret > 214748364 || (ret == 214748364 && pop > 7)) { return 0; }
            if (ret < -214748364 || (ret == -214748364 && pop < -8)) { return 0; }
            ret = ret * 10 + pop;
        }
        ret
    }
}
