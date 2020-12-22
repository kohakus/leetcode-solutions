// C++ solution.

class Solution {
public:
    string decodeString(string s) {
        int cur = 0;
        return decode(cur, s);
    }

    string decode(int& cur, const string& s) {
        int repeatn = 0;
        string substrs = "";
        for (; cur < s.size(); cur++) {
            char curChar = s[cur];
            if (isdigit(curChar)) {
                repeatn = repeatn * 10 + (curChar-'0');
            } else if (curChar == '[') {
                string repeats = decode(++cur, s);
                for (; repeatn > 0; repeatn--) { substrs += repeats; }
            } else if (curChar == ']') {
                return substrs;
            } else { substrs += curChar; }
        }
        return substrs;
    }
};