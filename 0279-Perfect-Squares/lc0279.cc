// C++ solution.

// Lagrange's Four Square theorem.
// Legendre's Three Square theorem.
// Time: O(\sqrt{N}), Space: O(1).
class Solution {
public:
    int numSquares(int n) {
        if (isSquare(n)) { return 1; }

        // Legendre's three square, let s = 4^k \times (8 \times m + 7)
        // if n % s == 0, it cannot be represented as 3-square.
        while (!(n & 3)) { n >>= 2; }
        if ((n&7) == 7) { return 4; }

        // check 2-square case.
        for (int i = 1; i <= intSqrt(n); i++) {
            if (isSquare(n - i*i)) { return 2; }
        }

        // the last case.
        return 3;
    }
private:
    inline bool isSquare(int n) {
        if (n < 0) { return false; }
        int n_sqrt = intSqrt(n);
        return n_sqrt*n_sqrt == n;
    }

    inline int intSqrt(int n) {
        double d(n);
        return static_cast<int>(std::sqrt(d) + 0.5);
    }
};

// DP. Time: O(N \sqrt(N)), Space: O(N).
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp.back();
    }
};