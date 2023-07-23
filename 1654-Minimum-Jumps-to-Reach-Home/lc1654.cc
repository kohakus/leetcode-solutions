// C++ solution.

// BFS.
// the key is to find a good upper bound.
// upper bound can be max(f+a+b, x+b)
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int far_pit = *std::max_element(forbidden.begin(), forbidden.end());
        int bound = std::max(far_pit+a+b, x+b);

        std::vector<bool> visited_by_forward(bound+1, false);
        std::vector<bool> visited_by_backward(bound+1, false);
        visited_by_forward[0] = true;

        for (int pitpos : forbidden) {
            visited_by_forward[pitpos] = true;
            visited_by_backward[pitpos] = true;
        }

        // (pos, frd, cnt)
        std::queue<std::tuple<int, bool, int>> que;
        que.emplace(0, true, 0);
        while (!que.empty()) {
            auto [pos, frd, cnt] = que.front();
            que.pop();
            if (pos == x) {
                return cnt;
            }
            // try move forward
            if (pos+a < bound+1 && !visited_by_forward[pos+a]) {
                visited_by_forward[pos+a] = true;
                que.emplace(pos+a, true, cnt+1);
            }
            // try move backward
            if (pos-b > 0 && frd && !visited_by_forward[pos-b] && !visited_by_backward[pos-b]) {
                visited_by_backward[pos-b] = true;
                que.emplace(pos-b, false, cnt+1);
            }
        }
        return -1;
    }
};