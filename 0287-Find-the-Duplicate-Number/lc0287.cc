// C++ solution.

// Floyd's Tortoise and Hare
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = 0, tortoise = 0;
        // phase 1
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (hare != tortoise);
        // phase 2
        tortoise = 0;
        do {
            tortoise = nums[tortoise];
            hare = nums[hare];
        } while (hare != tortoise);
        return hare;
    }
};