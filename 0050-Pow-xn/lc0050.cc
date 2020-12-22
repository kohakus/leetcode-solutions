// C++ solution.

class Solution {
public:
  double myPow(double x, int n) {
    if (n == std::numeric_limits<int>::lowest()){
      return myPow(1./x, -(n+1)) / x;
    }
    if (n < 0) {
      return myPow(1./x, -n);
    }

    double res = 1.;
    for (; n; n >>= 1) {
      if (n&1) { res *= x; }
      x *= x;
    }
    return res;
  }
};
