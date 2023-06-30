// C++ solution.

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }

    void generate(int n, int left, int right, string s, vector<string>& ans) {
        if (right == n) ans.push_back(s);
        if (left < n) {
            generate(n, left+1, right, s+"(", ans);
        }

        if (right < left) {
            generate(n, left, right+1, s+")", ans);
        }
    }
};
