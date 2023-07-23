// C++ solution.

// Consider of trie.
// Time complexity: O(\log^{2}N)
class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        uint64_t nn = n;
        uint64_t kk = k;
        for (--kk; kk > 0;) {
            uint64_t begin = ans;
            uint64_t last = begin + 1;
            uint64_t cnt = 0;
            for (;begin < nn+1; begin *= 10, last *= 10) {
                cnt += std::min(nn+1, last) - begin;
            }
            if (cnt <= kk) {
                 // increase the current prefix
                ans++;
                kk -= cnt;
            } else {
                // search more detailedly
                ans *= 10;
                --kk;
            }
        }
        return ans;
    }
};