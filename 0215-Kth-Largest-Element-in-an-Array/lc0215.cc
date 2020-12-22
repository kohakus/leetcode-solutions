// C++ solution.

// STL template algorithm: partial_sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin()+k, nums.end(), greater<int>());
        return nums[k-1];
    }
};

// STL template algorithm: make_heap, pop_heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k-1; i++) {
            pop_heap(nums.begin(), nums.end()-i);
        }
        return nums.front();
    }
};

// Quick select.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }

    int quickSelect(vector<int>& nums, int l, int r, int idx) {
        int axis = partition(nums, l, r);
        if (axis == idx) {
            return nums[axis];
        } else {
            return axis < idx ? quickSelect(nums, axis+1, r, idx) : quickSelect(nums, l, axis-1, idx);
        }
    }

    int partition(vector<int>& nums, int l, int r) {
        int random_pos = rand() % (r - l + 1) + l;
        swap(nums[r], nums[random_pos]);
        return _partition(nums, l, r);
    }

private:
    int _partition(vector<int>& nums, int l, int r) {
        int x = nums[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }
};