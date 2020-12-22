// C++ solution.

// sort + reordering: Time Complexity O(NlogN)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = (n + 1) / 2;

        std::vector<int> sorted_nums(nums);
        std::sort(sorted_nums.begin(), sorted_nums.end());

        for (int i = 0, j = mid-1; j >= 0; j--, i += 2) {
            nums[i] = sorted_nums[j];
        }
        for (int i = 1, j = n-1; j >= mid; j--, i += 2) {
            nums[i] = sorted_nums[j];
        }
    }
};


// median partition: Time complexity O(N)