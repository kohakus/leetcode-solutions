// C++ solution.

// reference from SGI-STL implementation
// 1. for bidirectional iterator: reverse method
// 2. for random access iterator: cyclic replacement

// reverse method
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t n = nums.size();
        if (k > n) { k = k % n; }
        size_t middle = n - static_cast<size_t>(k);
        if (middle == 0 || middle == n) { return; }

        std::reverse(nums.begin(), nums.begin()+middle);
        std::reverse(nums.begin()+middle, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

// cyclic replacement
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()) { k = k % nums.size(); }
        size_t middle = nums.size() - static_cast<size_t>(k);
        if (middle == 0 || middle == nums.size()) { return; }

        size_t n = _gcd(nums.size(), middle);
        while (n--) {
            _rotate_cycle(nums.begin(), nums.end(), nums.begin()+n, middle);
        }
    }

private:
    using iter = vector<int>::iterator;

    size_t _gcd(size_t m, size_t n) {
        while (n != 0) {
            size_t t = m % n;
            m = n;
            n = t;
        }
        return m;
    }

    void _rotate_cycle(iter first, iter last, iter initial, size_t shift) {
        int value = *initial;
        iter it1 = initial;
        iter it2 = it1 + shift;
        while (it2 != initial) {
            *it1 = *it2;

            // new it1 is old it2
            it1 = it2;

            // decide the position of new it2
            if (last - it2 > shift) {
                it2 += shift;
            } else {
                it2 = first + (shift - (last - it2));
            }
        }
        *it1 = value;
    }
};