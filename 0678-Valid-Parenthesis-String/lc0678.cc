// C++ solution.

// using two stack.
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftidx;
        stack<int> staridx;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftidx.push(i);
            } else if (s[i] == '*') {
                staridx.push(i);
            } else {
                if (!leftidx.empty()) {
                    leftidx.pop();
                } else if (!staridx.empty()) {
                    staridx.pop();
                } else {
                    return false;
                }
            }
        }

        while (!leftidx.empty()) {
            if (!staridx.empty() && leftidx.top() < staridx.top()) {
                leftidx.pop();
                staridx.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};

// One pass, count the open parenthesis.
// Count the number of ')' we are waiting for.
// cmax means the maximum number of unbalanced '(' that COULD be paired.
// cmin means the number of unbalanced '(' that MUST be paired.
class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;
        for (char c : s) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin = std::max(cmin-1, 0);
            } else {
                cmax++;
                cmin = std::max(cmin-1, 0);
            }
            if (cmax < 0) { return false; }
        }
        return cmin == 0;
    }
};