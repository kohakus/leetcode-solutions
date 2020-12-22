// C++ solution.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> tmp_eval;
        for (int i = 0; i < tokens.size(); i++) {
            std::string token = tokens[i];
            if (token.size() == 1 && !std::isdigit(token[0])) {
                int val2 = tmp_eval.top();
                tmp_eval.pop();
                int val1 = tmp_eval.top();
                tmp_eval.pop();

                switch (token[0]) {
                    case '+':
                        tmp_eval.push(val1 + val2);
                        break;
                    case '-':
                        tmp_eval.push(val1 - val2);
                        break;
                    case '*':
                        tmp_eval.push(val1 * val2);
                        break;
                    case '/':
                        tmp_eval.push(val1 / val2);
                    default:
                        break;
                }
            } else {
                tmp_eval.push(std::stoi(token));
            }
        }
        return tmp_eval.top();
    }
};