// C++ solution.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        backtrack(ans, res, s, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<string>>& ans, vector<string>& res, string& s, int pos) {
        int len = s.size();
        if (pos == len) {
            ans.push_back(res);
            return;
        }

        for (int i = pos; i < len; i++) {
            if (isPalindrome(s, pos, i)) {
                res.push_back(s.substr(pos, i-pos+1));
                backtrack(ans, res, s, i+1);
                res.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int begin, int last) {
        while (begin < last) {
            if (s[begin++] != s[last--]) {
                return false;
            }
        }
        return true;
    }
};