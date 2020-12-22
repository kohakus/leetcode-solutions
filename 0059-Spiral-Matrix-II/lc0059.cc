// C++ solution.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::array<std::array<int, 2>, 4> directions{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
        std::array<int, 2> num_steps{n, n-1};

        int xpos = -1;
        int ypos = 0;
        int direction = 0;
        int axis = direction & 1;
        int cnt = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        while (num_steps[axis] > 0) {
            for (int i = 0; i < num_steps[axis]; i++) {
                xpos += directions[direction][1];
                ypos += directions[direction][0];
                ans[ypos][xpos] = cnt++;
            }
            num_steps[axis]--;
            direction = (1 + direction) % 4;
            axis = direction & 1;
        }
        return ans;
    }
};