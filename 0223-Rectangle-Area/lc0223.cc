// C++ solution.

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rect1_area = (C - A) * (D - B);
        int rect2_area = (G - E) * (H - F);

        // cross point of bottom-left
        int a = max(A, E);
        int b = max(B, F);

        // cross point of top-right
        int c = min(C, G);
        int d = min(D, H);

        // case1: the rectangles do not intersect
        if (a >= c || b >= d) {
            return rect1_area + rect2_area;
        }

        // case2: the rectangles are intersected
        return rect1_area - (c - a) * (d - b) + rect2_area;
    }
};