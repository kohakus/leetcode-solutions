// C++ solution.

class Solution {
public:
    inline int findRType(char par) {
        if (par == ')') { return 0; }
        if (par == '}') { return 1; }
        if (par == ']') { return 2; }
        return -1;
    }

    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            int rtype = findRType(c);
            if (rtype >= 0) {
                if (stk.empty()) { return false; }
                if (stk.top() != lpar[rtype]) { return false; }
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }

private:
    const array<char, 3> lpar{'(', '{', '['};
    const array<char, 3> rpar{')', '}', ']'};
};