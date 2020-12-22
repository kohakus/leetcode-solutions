// C++ solution.

// monostack method.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // the temperature with its index
        stack<pair<int, int>> monostack;
        int num_days = T.size();
        vector<int> ans(num_days, 0);
        for (int i = 0; i < num_days; i++) {
            int curr_val = T[i];
            while (!monostack.empty() && monostack.top().first < curr_val) {
                int top_idx = monostack.top().second;
                ans[top_idx] = i - top_idx;
                monostack.pop();
            }
            monostack.push(make_pair(curr_val, i));
        }
        return ans;
    }
};