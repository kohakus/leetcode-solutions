// C++ solution.

class Solution {
public:
    string addStrings(string num1, string num2) {
        int pos1 = num1.size() - 1;
        int pos2 = num2.size() - 1;
        string ans = "";
        int carry = 0;
        while (pos1 >= 0 || pos2 >= 0 || carry > 0) {
            int val1 = pos1 >= 0 ? num1[pos1] - '0' : 0;
            int val2 = pos2 >= 0 ? num2[pos2] - '0' : 0;
            int sum_tmp = carry + val1 + val2;
            ans.push_back('0' + sum_tmp % 10);
            carry = sum_tmp / 10;
            pos1--;
            pos2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};