// C++ solution.

// Fundamental Theorem Of Arithmetic
class Solution {
public:
    bool isUgly(int num) {
        array<int, 3> factors = {2, 3, 5};
        for (int p : factors) {
            while (num && num % p == 0) {
                num /= p;
            }
        }
        return num == 1;
    }
};