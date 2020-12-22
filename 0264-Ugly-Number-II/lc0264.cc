// C++ solution.

// the ugly number is the combination of multiplication of [2, 3, 5]
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly{1};
        int i = 0, j = 0, k = 0;
        while (ugly.size() < n) {
            ugly.push_back(min(ugly[i]*2, min(ugly[j]*3, ugly[k]*5)));
            if (ugly.back() == ugly[i]*2) { ++i; }
            if (ugly.back() == ugly[j]*3) { ++j; }
            if (ugly.back() == ugly[k]*5) { ++k; }
        }
        return ugly.back();
    }
};