// C++ solution.

// Hash table + min-heap. Time Complexity: O(NlogK)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using hashIter = unordered_map<int, size_t>::iterator;
        unordered_map<int, size_t> counter;

        // we use min-heap to maintin top k
        auto cmp = [](const hashIter& lhs, const hashIter& rhs) {
            return lhs->second > rhs->second;
        };
        priority_queue<hashIter, vector<hashIter>, decltype(cmp)> topk(cmp);

        for (int num : nums) {
            counter[num]++;
        }
        for (hashIter it = counter.begin(); it != counter.end(); it++) {
            topk.push(it);
            if (topk.size() > k) { topk.pop(); }
        }

        // get top k freq value
        vector<int> ans;
        while (!topk.empty()) {
            ans.push_back(topk.top()->first);
            topk.pop();
        }
        return ans;
    }
};