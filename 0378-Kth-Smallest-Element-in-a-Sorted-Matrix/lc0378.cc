// C++ solution.

// using heap, Time complexity: O(KlogR)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        std::priority_queue<HeapNode> minheap;

        for (int i = 0; i < n; i++) {
            minheap.push(HeapNode(matrix[i][0], i, 0));
        }

        int cnt = k;
        int ans = 0;
        while (cnt--) {
            HeapNode node = minheap.top();
            minheap.pop();
            ans = node.value();
            if (node.jpos() < n-1) {
                int ipos = node.ipos();
                int jpos = node.jpos();
                minheap.push(HeapNode(matrix[ipos][jpos+1], ipos, jpos+1));
            }
        }
        return ans;
    }

private:
    // (val, (i, j)): value and the corresponding position.
    using Node = std::pair<int, std::pair<int, int>>;

    struct HeapNode {
        HeapNode(int val, int i, int j)
            : _node(std::make_pair(val, std::make_pair(i, j))) {}

        inline int ipos() const {
            return _node.second.first;
        }

        inline int jpos() const {
            return _node.second.second;
        }

        inline int value() const {
            return _node.first;
        }

        inline bool operator<(const HeapNode& rhs) const {
            return value() > rhs.value();
        }

        Node _node;
    };
};