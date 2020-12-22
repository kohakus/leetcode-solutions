// C++ solution.

// pay attention to some cases:
// 1. leading whitespaces should be discarded;
// 2. the number can be negative;
// 3. deal with overflow carefully, because we can only use 32-bits type;
// 4. the input can be invalid (contains invalid characters)
class Solution {
public:
    int myAtoi(string str) {
        int cursor = 0;
        while (str[cursor] == ' ') { cursor++; }

        int sign = 1;
        if (str[cursor] == '-' || str[cursor] == '+') {
            sign = str[cursor++] == '-' ? -1 : 1;
        }

        int ans = 0;
        for (; cursor < str.size() && std::isdigit(str[cursor]); cursor++) {
            // here we use INT_MAX (2147483647) directly
            if (ans > 214748364 || (ans == 214748364 && str[cursor] > '7')) {
                return (sign == 1) ? 2147483647 : -2147483648;
            }
            ans = ans * 10 + (str[cursor] - '0');
        }
        return ans * sign;
    }
};