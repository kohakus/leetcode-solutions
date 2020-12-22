// C++ solution.

// use fenwick tree (i.e. binary index tree)

class NumArray {
public:
    NumArray(vector<int>& nums)
            : size_(nums.size()),
              nums_(nums) {
        bit_.resize(size_+1);
        for (int idx = 1; idx <= size_; idx++) {
            add(idx, nums_[idx-1]);
        }
    }

    inline int size() const {
        return size_;
    }

    void update(int i, int val) {
        int diff = val - nums_[i];
        if (diff != 0) {
            nums_[i] = val;
            add(i+1, diff);
        }
    }

    int sumRange(int i, int j) {
        return query(j+1) - query(i);
    }

private:
    inline int lowBit(const int idx) const {
        return idx & -idx;
    }

    void add(const int idx, const int val) {
        int pos = idx;
        while (pos <= size_) {
            bit_[pos] += val;
            pos += lowBit(pos);
        }
    }

    int query(const int idx) const {
        int sum = 0;
        int pos = idx;
        while (pos > 0) {
            sum += bit_[pos];
            pos -= lowBit(pos);
        }
        return sum;
    }

    int size_;
    vector<int> nums_;
    vector<int> bit_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */