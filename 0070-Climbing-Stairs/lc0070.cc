// C++ solution.

// simple iterative method
class Solution {
public:
    int climbStairs(int n) {
        int s0 = 1, s1 = 1;
        while (n-- > 1) {
            s1 += s0;
            s0 = s1 - s0;
        }
        return s1;
    }
};

// Cassini Identity O(logN)
class Solution {
public:
    int climbStairs(int n) {
        int res[4] = {1, 0, 0, 1};
        int tmp[4] = {1, 1, 1, 0};
        for (; n; n >>= 1) {
            if (n&1) { matrixProd(res, tmp); }
            if (n>1) { matrixProd(tmp, tmp); }
        }
        return res[0];
    }

private:
    void matrixProd(int l[4], int r[4]) {
        int a = l[0] * r[0] + l[1] * r[2];
        int b = l[0] * r[1] + l[1] * r[3];
        int c = l[2] * r[0] + l[3] * r[2];
        int d = l[2] * r[1] + l[3] * r[3];
        l[0] = a;
        l[1] = b;
        l[2] = c;
        l[3] = d;
    }
};
