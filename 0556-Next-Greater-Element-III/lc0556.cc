// C++ solution.

// solution with trick: use str to represent the given integer.
class Solution {
public:
    int nextGreaterElement(int n) {
        std::string num = std::to_string(n);
        std::next_permutation(num.begin(), num.end());
        int64_t next_num = std::stoll(num);
        return (next_num > numeric_limits<int>::max() || next_num <= n) ? -1 : next_num;
    }
};