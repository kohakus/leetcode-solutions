// C++ solution.

// Two pointers.
// 1. The widest container is a good candidate. Its water level is the height of the smaller one of first and last line.
// 2. All other containers are less wide and thus would need a higher water level in order to hold more water.
// 3. The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int pos_l = 0;
        int pos_r = height.size()-1;
        int max_water = 0;
        while (pos_l < pos_r) {
            int water_level = std::min(height[pos_l], height[pos_r]);
            max_water = std::max(max_water, water_level * (pos_r-pos_l));
            if (height[pos_l] < height[pos_r]) {
                pos_l++;
            } else {
                pos_r--;
            }
        }
        return max_water;
    }
};