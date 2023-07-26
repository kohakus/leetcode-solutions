// C++ solution.

// Greedy.
// Time complexity: O(N)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start_pos = 0;
        int tank = 0;
        int total = 0;
        for (int i = 0; i < gas.size(); i++) {
            int delta = gas[i] - cost[i];
            total += delta;
            if (tank + delta < 0) {
                tank = 0;
                start_pos = i+1;
            } else {
                tank += delta;
            }
        }
        return total < 0 ? -1 : start_pos;
    }
};