// C++ solution.

// Two pointers.
// 1. The widest container is a good candidate. Its water level is the height of the smaller one of first and last line.
// 2. All other containers are less wide and thus would need a higher water level in order to hold more water.
// 3. The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int lpos = 0;
        int rpos = height.size() - 1;
        for (;lpos < rpos;) {
            ans = std::max(ans, std::min(height[lpos], height[rpos]) * (rpos-lpos));
            height[lpos] < height[rpos] ? lpos++ : rpos--;
        }
        return ans;
    }
};
