// C++ solution.

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> ret(numRows, "");
    int rowCursor = 0;
    bool trigger = false;

    for (char &c : s) {
      ret[rowCursor].push_back(c);
      rowCursor += trigger? -1 : 1;
      if (rowCursor == 0 || rowCursor == numRows-1) {
        trigger = !trigger;
      }
    }

    string ret_s = "";
    for (const string &piece : ret) ret_s += piece;
    return ret_s;
  }
};
