// C++ solution.

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }

private:
    bool isPalindrome(string& s, int l, int r) {
        int i = l;
        int j = r;
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};