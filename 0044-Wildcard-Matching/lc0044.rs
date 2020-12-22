// Rust solution.

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s: Vec<u8> = s.into_bytes();
        let p: Vec<u8> = p.into_bytes();
        let (ssize, psize) = (s.len(), p.len());
        let (mut spointer, mut ppointer) = (0_usize, 0_usize);
        let mut smatch = 0_usize;
        let mut starrecord: i32 = -1;
        while spointer < ssize {
            if ppointer < psize && (s[spointer] == p[ppointer] || p[ppointer] == b'?') {
                spointer += 1;
                ppointer += 1;
            } else if ppointer < psize && p[ppointer] == b'*' {
                starrecord = ppointer as i32;
                ppointer += 1;
                smatch = spointer;
            } else if starrecord >= 0 {
                ppointer = starrecord as usize + 1;
                smatch += 1;
                spointer = smatch;
            } else { return false; }
        }
        while ppointer < psize && p[ppointer] == b'*' { ppointer += 1; }
        ppointer == p.len()
    }
}
