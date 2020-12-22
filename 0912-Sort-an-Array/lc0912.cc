// C++ solution.

// Quick Sort.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        vector<int> num_arr(nums);
        quickSort(num_arr, 0, nums.size()-1);
        return num_arr;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int axis = partition(nums, l, r);
            quickSort(nums, l, axis - 1);
            quickSort(nums, axis + 1, r);
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

// Merge Sort.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (_buffer.size() < nums.size()) {
            _buffer.resize(nums.size(), 0);
        }

        vector<int> num_arr(nums);
        mergeSort(num_arr, 0, nums.size()-1);
        return num_arr;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) { return; }
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        // merge two sorted arr.
        int i = l;
        int j = mid + 1;
        int cur = 0;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                _buffer[cur++] = nums[i++];
            } else {
                _buffer[cur++] = nums[j++];
            }
        }
        while (i <= mid) {
            _buffer[cur++] = nums[i++];
        }
        while (j <= r) {
            _buffer[cur++] = nums[j++];
        }

        // copy to original array.
        for (int k = 0; k < r - l + 1; k++) {
            nums[l+k] = _buffer[k];
        }
    }

private:
    vector<int> _buffer;
};