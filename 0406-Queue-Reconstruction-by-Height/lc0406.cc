// C++ solution.

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const vector<int>& q1, const vector<int>& q2) -> bool {
            if (q1.front() == q2.front()) { return q1.back() > q2.back(); }
            return q1.front() < q2.front();
        };

        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans(people.size(), vector<int>());
        for (vector<int>& person : people) {
            int cnt = 0, idx = 0;
            for (; idx < people.size(); idx++) {
                if (ans[idx].empty()) {
                    if (cnt++ == person.back()) {
                        ans[idx] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};