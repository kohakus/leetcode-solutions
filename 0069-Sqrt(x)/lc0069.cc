// C++ solution.

// Binary search
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) { return x; }
        int lpos = 0;
        int rpos = x;
        int ans = 0;
        while (lpos < rpos) {
            int mid = lpos + (rpos - lpos) / 2;
            int tmp = x / mid;
            if (mid == tmp) {
                return mid;
            } else if (mid > tmp) {
                rpos = mid;
            } else {
                lpos = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};


// Newton Iteration Method
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) { return x; }
        double pre = 0;
        double cur = 1;
        while (fabs(cur - pre) > 1e-6) {
            pre = cur;
            cur = pre / 2.0 + x / (2 * pre);
        }
        return static_cast<int>(cur);
    }
};