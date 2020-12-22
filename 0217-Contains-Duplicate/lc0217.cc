// C++ solution.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> buckets;
        for (int num : nums) {
            if (buckets.find(num) != buckets.end()) {
                return true;
            }
            buckets.insert(num);
        }
        return false;
    }
};