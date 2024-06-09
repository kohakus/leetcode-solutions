// C++ solution.

// STL template algorithm: partial_sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::partial_sort(nums.begin(), nums.begin()+k, nums.end(), std::greater<int>());
        return nums[k-1];
    }
};

// STL template algorithm: make_heap, pop_heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k-1; i++) {
            std::pop_heap(nums.begin(), nums.end()-i);
        }
        return nums.front();
    }
};

// Quick select.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }

    int quickSelect(std::vector<int>& nums, int lpos, int rpos, int idx) {
        int axisl = lpos;
        int axisr = rpos;
        partition(nums, axisl, axisr);
        if (axisl > idx) {
            return quickSelect(nums, lpos, axisl-1, idx);
        } else if (axisr < idx) {
            return quickSelect(nums, axisr+1, rpos, idx);
        } else {
            return nums[idx];
        }
    }

    void partition(std::vector<int>& nums, int& lpos, int& rpos) {
        int randpos = std::rand() % (rpos-lpos+1) + lpos;
        int x = nums[randpos];
        int mid = lpos;
        for (;mid <= rpos;) {
            if (nums[mid] == x) {
                mid++;
            } else if (nums[mid] < x) {
                std::swap(nums[lpos++], nums[mid++]);
            } else {
                std::swap(nums[mid], nums[rpos--]);
            }
        }
    }
};
