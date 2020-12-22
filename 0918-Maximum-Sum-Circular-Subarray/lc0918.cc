// C++ solution.

// Kadane's Algorithm
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.empty()) { return 0; }
        int total = 0;
        int max_sum = A[0];
        int max_acc = 0;
        int min_sum = A[0];
        int min_acc = 0;
        for (int a : A) {
            max_acc = max(max_acc + a, a);
            max_sum = max(max_sum, max_acc);
            min_acc = min(min_acc + a, a);
            min_sum = min(min_sum, min_acc);
            total += a;
        }
        return max_sum < 0 ? max_sum : max(max_sum, total - min_sum);
    }
};