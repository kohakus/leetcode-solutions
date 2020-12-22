// C++ solution.

// Greedy, try to insert different tasks into interval.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> ntasks{};
        int max_freq = 0;

        for (char c : tasks) {
            ntasks[c-'A']++;
            max_freq = max(max_freq, ntasks[c-'A']);
        }

        int ans = (max_freq-1) * (n+1);
        for (int i = 0; i < 26; i++) {
            if (ntasks[i] == max_freq) { ans++; }
        }
        return tasks.size() > ans ? tasks.size() : ans;
    }
};