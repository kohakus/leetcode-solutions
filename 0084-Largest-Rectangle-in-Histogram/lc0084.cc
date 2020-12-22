// C++ solution.

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int max_area = 0;
    stack<int> idxes;
    idxes.push(0);
    heights.push_back(0);
    for (int i = 1; i < heights.size(); i++) {
      while (!idxes.empty() && heights[i] < heights[idxes.top()]) {
        int h = heights[idxes.top()];
        idxes.pop();
        int prev = idxes.empty() ? -1 : idxes.top();
        max_area = max(max_area, (i-prev-1) * h);
      }
      idxes.push(i);
    }
    return max_area;
  }
};
