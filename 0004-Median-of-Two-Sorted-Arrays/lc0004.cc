// C++ solution.

// merge sorted arrays and find target
// Time complexity: O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size = nums1.size() + nums2.size();
        int target_cnt = (total_size >> 1) + 1;

        int target_prev = 0;
        int target = 0;

        int nums1_pos = 0;
        int nums2_pos = 0;

        for (int i = 0; i < target_cnt; i++) {
            target_prev = target;
            if (nums1_pos < nums1.size() && (nums2_pos >= nums2.size() || nums1[nums1_pos] <= nums2[nums2_pos])) {
                target = nums1[nums1_pos++];
            } else {
                target = nums2[nums2_pos++];
            }
        }
        if (total_size & 1) {
            target_prev = target;
        }
        return static_cast<double>(target_prev+target) / 2.0;
    }
};

// Binary search
// Time complexity: O(log(m+n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size = nums1.size() + nums2.size();
        int kth = (total_size >> 1) + 1;
        if (total_size & 1) {
            return findKthFromTwoArrays(nums1, nums2, kth);
        } else {
            return (findKthFromTwoArrays(nums1, nums2, kth-1) + findKthFromTwoArrays(nums1, nums2, kth)) / 2.0;
        }
    }

    double findKthFromTwoArrays(vector<int>& nums1, vector<int>& nums2, int k) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int nums1_pos = 0;
        int nums2_pos = 0;

        for (;;) {
            if (nums1_pos >= nums1_size) {
                return static_cast<double>(nums2[nums2_pos+k-1]);
            }
            if (nums2_pos >= nums2_size) {
                return static_cast<double>(nums1[nums1_pos+k-1]);
            }
            if (k == 1) {
                return static_cast<double>(std::min(nums1[nums1_pos], nums2[nums2_pos]));
            }

            int target_cnt = (k >> 1) - 1;
            int nums1_find_pos = std::min(nums1_pos+target_cnt, nums1_size-1);
            int nums2_find_pos = std::min(nums2_pos+target_cnt, nums2_size-1);

            int nums1_find_val = nums1[nums1_find_pos];
            int nums2_find_val = nums2[nums2_find_pos];

            if (nums1_find_val < nums2_find_val) {
                k -= nums1_find_pos - nums1_pos + 1;
                nums1_pos = nums1_find_pos + 1;
            } else {
                k -= nums2_find_pos - nums2_pos + 1;
                nums2_pos = nums2_find_pos + 1;
            }
        }
    }
};
