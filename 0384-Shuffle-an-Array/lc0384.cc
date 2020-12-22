// C++ solution.

// Fisher–Yates shuffle Algorithm.
class Solution {
public:
    Solution(vector<int>& nums) : _nums(nums) {
        srand(time(nullptr));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(_nums);
        int n = ans.size();

        // Start from the last element and swap one by one
        // Note that we don't need to run for the first element
        for (int i = n-1; i > 0; i--) {
            // pick a random index in range [0, i]
            int picked = rand() % (i + 1);
            swap(ans[i], ans[picked]);
        }
        return ans;
    }

private:
    vector<int> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */