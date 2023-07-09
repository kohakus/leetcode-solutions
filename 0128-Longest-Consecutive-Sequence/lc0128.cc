// C++ solution.

// UnionFind.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        UnionFind disjoint_set(nums.size());
        std::unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) { continue; }
            hash[nums[i]] = i;
            if (hash.find(nums[i]-1) != hash.end()) {
                disjoint_set.gunion(i, hash[nums[i]-1]);
            }
            if (hash.find(nums[i]+1) != hash.end()) {
                disjoint_set.gunion(i, hash[nums[i]+1]);
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, disjoint_set.gsize(i));
        }
        return ans;
    }


class UnionFind {
public:
    UnionFind(const int n)
             : _p(n), _gsize(n), _cnt(n) {
        for (int i = 0; i < n; i++) {
            _p[i] = i;
            _gsize[i] = 1;
        }
    }

    int gfind(const int x) {
        return x == _p[x] ? x : (_p[x] = gfind(_p[x]));
    }

    int gsize(const int x) {
        return _gsize[gfind(x)];
    }

    int size() const {
        return _cnt;
    }

    void gunion(const int x, const int y) {
        int px = gfind(x);
        int py = gfind(y);
        if (px != py) {
            _p[px] = py;
            _gsize[py] += _gsize[px];
            _cnt--;
        }
    }

    bool connected(const int x, const int y) {
        return gfind(x) == gfind(y);
    }

private:
    std::vector<int> _p;
    std::vector<int> _gsize;
    int _cnt;
};

};

// Hash.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(make_move_iterator(nums.begin()),
                                   make_move_iterator(nums.end()));
        int ans = 0;
        for (int num : num_set) {
            if (!num_set.count(num-1)) {
                int cur_len = 1;
                for (; num_set.count(num+1); num++) {
                    cur_len++;
                }
                ans = max(ans, cur_len);
            }
        }
        return ans;
    }
};