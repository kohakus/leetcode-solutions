// C++ solution.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            cnt++;
            // set the lowest 1 to 0
            n = n & (n-1);
        }
        return cnt;
    }
};