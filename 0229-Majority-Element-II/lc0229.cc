// C++ solution.

// Moore voting.
// Time complexity: O(N), Space complexity: O(1).
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Candidates and their counters.
        int num1 = -1;
        int num2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;

        // the first pass: find two candidates.
        for (int num : nums) {
            if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            } else if (cnt1 == 0) {
                num1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                num2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // the second pass: check if the candidates are valid.
        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums) {
            if (num == num1) {
                cnt1++;
            }
            if (num == num2) {
                cnt2++;
            }
        }

        vector<int> ans;
        int threshold = nums.size() / 3;
        if (cnt1 > threshold) { ans.push_back(num1); }
        if (cnt2 > threshold) { ans.push_back(num2); }
        return ans;
    }
};