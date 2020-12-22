// C++ solution.

// the monotonic stack is naturally used, making the implementation easier.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> monostack;
        int rangel = nums.size(), ranger = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!monostack.empty() && nums[monostack.top()] > nums[i]) {
                rangel = min(rangel, monostack.top());
                monostack.pop();
            }
            monostack.push(i);
        }

        // idiom method to clearing container.
        stack<int>().swap(monostack);
        for (int i = nums.size()-1; i >= 0; i--) {
            while (!monostack.empty() && nums[monostack.top()] < nums[i]) {
                ranger = max(ranger, monostack.top());
                monostack.pop();
            }
            monostack.push(i);
        }
        return ranger > rangel ? ranger-rangel+1 : 0;
    }
};