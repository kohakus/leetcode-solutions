// C++ solution.

// Each prefix of a balanced parentheses has a number of open parentheses
// greater or equal than closed parentheses, similar idea with each suffix.

// To make the string valid with minimum removals, we need to get rid of all
// parentheses that do not have a matching pair.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // use stack to store the index of open parentheses
        std::stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            if (s[i] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    // use placeholder as delete label
                    s[i] = '*';
                }
            }
        }

        // deal with invalid open parentheses
        while (!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }

        // C++ Erase–remove idiom
        // https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};