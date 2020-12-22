// C++ solution.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == numeric_limits<int>::min()) {
            if (dividend == numeric_limits<int>::min()) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dividend == numeric_limits<int>::min()) {
            if (divisor == -1) {
                return numeric_limits<int>::max();
            }
            if (divisor > 0) {
                return -1 + divide(dividend+divisor, divisor);
            } else if (divisor < 0) {
                return 1 + divide(dividend-divisor, divisor);
            }
        }

        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }

        dividend = dividend > 0 ? dividend : -dividend;
        divisor = divisor > 0 ? divisor : -divisor;
        int remainder = dividend, quotient = 0;
        while (remainder >= divisor) {
            int shift = 0;
            while ((divisor << shift) <= remainder && (divisor << shift) > 0) {
                ++shift;
            }
            --shift;
            quotient += (1 << shift);
            remainder -= (divisor << shift);
        }
        if (sign < 0){ quotient = -quotient; }
        return quotient;
    }
};