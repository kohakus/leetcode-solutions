// C++ solution.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) { return {}; }
        std::array<std::array<int, 2>, 4> directions{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
        int h = matrix.size();
        int w = matrix.front().size();
        std::array<int, 2> num_steps{w, h-1};

        int xpos = -1;
        int ypos = 0;
        int direction = 0;
        int axis = direction & 1;
        vector<int> ans;
        while (num_steps[axis] > 0) {
            for (int i = 0; i < num_steps[axis]; i++) {
                ypos += directions[direction][0];
                xpos += directions[direction][1];
                ans.push_back(matrix[ypos][xpos]);
            }
            num_steps[axis]--;
            direction = (direction + 1) % 4;
            axis = direction & 1;
        }
        return ans;
    }
};