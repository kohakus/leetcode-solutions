// C++ solution.

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    int sz = digits.size();
    if (sz > 0) {
      res = string(sz, '0');
      backtracking(0, sz, digits);
    }
    return ans;
  }

  void backtracking(int depth, const int sz, string& digits) {
    if (depth == sz) {
      ans.push_back(res);
      return;
    }

    int button = digits[depth] - '0';
    for (int i = 0; i < dig[button].size(); i++) {
      res[depth] = dig[button][i];
      backtracking(depth+1, sz, digits);
    }
  }

private:
  string dig[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> ans;
  string res;
};
