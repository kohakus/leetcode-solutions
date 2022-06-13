// C++ solution.

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int K = min(m-1, n-1);
        long ans = 1;

        // C(n,k) = (n-k+1)/k * C(n,k-1)
        for (int k = 1; k <= K; k++) {
            ans = (N-k+1) * ans / k;
        }

        return ans;
    }
};
