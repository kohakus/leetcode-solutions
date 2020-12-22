// C++ solution.

// some key points:
// 1. overflow, example: INT_MIN / -1
// 2. there may be some decimal numbers before the recurring part
// 3. the recurring part may contain multiple numbers
// 4. deal with special cases: numerator is zero, sign of number ...

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) { return "0"; }
        std::string ans;
        if (numerator > 0 ^ denominator > 0) {
            ans += '-';
        }

        long numer = std::abs(static_cast<long>(numerator));
        long denom = std::abs(static_cast<long>(denominator));
        long r = numer % denom;

        ans += std::to_string(numer / denom);
        if (r == 0) { return ans; }

        ans += '.';
        std::unordered_map<long, size_t> logger;
        while (r) {
            if (logger.find(r) != logger.end()) {
                ans.insert(logger[r], 1, '(');
                ans += ')';
                break;
            }
            logger[r] = ans.size();
            r *= 10;
            ans += std::to_string(r / denom);
            r %= denom;
        }
        return ans;
    }
};