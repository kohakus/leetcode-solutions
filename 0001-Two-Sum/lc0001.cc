// C++ solution.
// Efficient one pass method with search tree.

// using iteration loop
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> posMap;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            map<int, int>::iterator posIter = posMap.find(target - *it);
            int idx = std::distance(nums.begin(), it);
            if (posIter == posMap.end()) {
                posMap[*it] = idx;
            } else {
                return {posIter->second, idx};
            }
        }
        return {};
    }
};

// using straightforward loop
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> posMap;
        for (int i = 0; i < nums.size(); i++) {
            int conum = target - nums[i];
            if (posMap.find(conum) == posMap.end()) {
                posMap[nums[i]] = i;
            } else {
                return {posMap[conum], i};
            }
        }
        return {};
    }
};