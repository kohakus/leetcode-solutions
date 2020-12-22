// C++ solution.

class Solution {
public:
    int getSum(int a, int b) {
        // treat xor as addition without carry
        int c = 0;
        while (b) {
            c = a ^ b;
            // let the minus bit overflow
            b = static_cast<uint32_t>((a & b)) << 1;
            a = c;
        }
        return c;
    }
};