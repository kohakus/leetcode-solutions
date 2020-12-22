// C++ solution.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int pos = digits.size()-1; pos >= 0; pos--) {
            if (digits[pos] == 9) {
                digits[pos] = 0;
            } else {
                digits[pos] += 1;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};