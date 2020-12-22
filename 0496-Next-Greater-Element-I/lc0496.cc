// C++ solution.

// Monostack method.
// Time complexity: O(N).
// the key idea is to use a stack to keep a decreasing sub-sequence.
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        stack<int> monostack;
        for (int num : nums2) {
            while (!monostack.empty() && monostack.top() < num) {
                hash[monostack.top()] = num;
                monostack.pop();
            }
            monostack.push(num);
        }

        int n = nums1.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            auto qurey = hash.find(nums1[i]);
            ans[i] = (qurey == hash.end()) ? -1 : qurey->second;
        }
        return ans;
    }
};