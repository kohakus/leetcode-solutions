// C++ solution.

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) { return true; }
        size_t lpos = 0;
        size_t rpos = s.size()-1;
        while (lpos < rpos) {
            if (!isValid(s[lpos])) {
                lpos++;
            } else if (!isValid(s[rpos])) {
                rpos--;
            } else {
                if (!check(s[lpos++], s[rpos--])) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    inline bool isValid(unsigned char c) {
        return (std::isalpha(c) || std::isdigit(c)) ? true : false;
    }

    inline bool check(unsigned char c1, unsigned char c2) {
        return std::tolower(c1) == std::tolower(c2);
    }
};