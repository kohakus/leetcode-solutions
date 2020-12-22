// C++ solution.

// brute force searching.
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> vals;
        for (int num : nums) {
            vals.push_back(static_cast<double>(num));
        }
        return _dfs(vals);
    }

private:
    inline bool _equal24(double val) {
        if (fabs(val - 24.0) <= _eps) {
            return true;
        }
        return false;
    }

    inline vector<double> compute(double a, double b) {
        return vector<double>{a+b, a-b, b-a, a/b, b/a, a*b};
    }

    bool _dfs(vector<double> vals) {
        if (vals.size() == 1) {
            return _equal24(vals.back()) ? true : false;
        }
        // select two values each time
        for (int i = 0; i < vals.size(); i++) {
            for (int j = i+1; j < vals.size(); j++) {
                vector<double> next_vals;
                for (int k = 0; k < vals.size(); k++) {
                    if (k != i && k != j) {
                        next_vals.push_back(vals[k]);
                    }
                }
                // select possible operations
                vector<double> res = compute(vals[i], vals[j]);
                for (double v : res) {
                    next_vals.push_back(v);
                    if (_dfs(next_vals)) {
                        return true;
                    }
                    next_vals.pop_back();
                }
            }
        }
        return false;
    }

    // epsilon for equal checking.
    double _eps{0.00001};
};