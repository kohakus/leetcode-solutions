// C++ solution.

// number theory.
// after any steps, there is at most one jug is in part state.
// after any steps, the total water in the two jugs must be a multiple of GCD(x, y).
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) { return true; }
        if (static_cast<int64_t>(x)+y < z) { return false; }
        return z % gcd(x, y) == 0;
    }

private:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x%y);
    }
};