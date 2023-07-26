// C++ solution.

// Bit operation
// Use xor to sign different bits, and then find how many are they
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int cnt = 0;
        for (; diff != 0; cnt++) {
            diff &= diff - 1;
        }
        return cnt;
    }
};