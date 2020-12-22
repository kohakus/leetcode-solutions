// C++ solution.

// num1[i] * num2[j] will be placed at indices [i + j, i + j + 1]
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> pos(m+n, 0);

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                int idx1 = i + j;
                int idx2 = idx1 + 1;
                int temp = (num1[i] - '0') * (num2[j] - '0');

                temp = temp + pos[idx2];
                pos[idx1] += temp / 10;
                pos[idx2] = temp % 10;
            }
        }

        string ans;
        for (int num : pos) {
            if (ans.empty() && num == 0) { continue; }
            ans.push_back(static_cast<char>(num)+'0');
        }
        return ans.empty() ? "0" : ans;
    }
};