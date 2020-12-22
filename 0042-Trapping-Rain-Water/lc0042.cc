// C++ solution.

// Similar to question 11. We can use two pointers method.
// Instead of calculating area by height*width, we can think it in a cumulative way.
// Search from left to right and maintain a max height of left and right separately,
// which is like a one-side wall of partial container.
// If current height of left is lower, we fill water in the left bin, and vice versa.
// Until left meets right, we filled the whole container.
class Solution {
public:
    int trap(vector<int>& height) {
        int posl = 0;
        int posr = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int ans = 0;
        while (posl < posr) {
            if (height[posl] < height[posr]) {
                left_max = std::max(left_max, height[posl]);
                ans += left_max - height[posl++];
            } else {
                right_max = std::max(right_max, height[posr]);
                ans += right_max - height[posr--];
            }
        }
        return ans;
    }
};

// Just use monostack.
// Use a stack to preserve a descending sequence.
// For example: [3,2,1,0,3]
// *---*
// **--*
// ***-*
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> monostack;
        int water = 0;
        for (int i = 0; i < height.size();) {
            if (monostack.empty() || height[i] <= height[monostack.top()]) {
                monostack.push(i++);
            } else {
                int bar = monostack.top();
                monostack.pop();
                if (!monostack.empty()) {
                    int lower_level = std::min(height[monostack.top()], height[i]);
                    water += (lower_level - height[bar]) * (i - monostack.top() - 1);
                }
            }
        }
        return water;
    }
};