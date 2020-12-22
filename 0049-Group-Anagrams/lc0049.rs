// Rust solution.

use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let countsort = |s: &str| {
            s.bytes().fold([0;26], |mut buckets, c| {
                buckets[(c - b'a') as usize] += 1_u32;
                buckets
            })
        };

        let map = strs.into_iter().fold(HashMap::new(), |mut hash, s| {
            hash.entry(countsort(&s)).or_insert(Vec::new()).push(s);
            hash
        });

        map.into_iter().map(|(_, v)| v).collect::<Vec<_>>()
    }
}
