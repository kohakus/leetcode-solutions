// C++ solution.

// simple hash table solution.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for (int num : nums1) {
            hash[num]++;
        }

        vector<int> ans;
        for (int num : nums2) {
            if (hash.find(num) != hash.end()) {
                if (hash[num]-- > 0) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};