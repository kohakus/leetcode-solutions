// C++ solution.

// basic backtracking to find a valid itinerary.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> logger;
        for (auto& ticket : tickets) {
            logger[ticket[0]][ticket[1]]++;
        }
        string start = "JFK";
        vector<string> ans;
        ans.push_back(start);
        dfs(logger, ans, start, tickets.size()+1);
        return ans;
    }

private:
    bool dfs(unordered_map<string, map<string, int>>& logger, vector<string>& ans, const string& curr, int n) {
        if (ans.size() == n) { return true; }
        for (auto& item : logger[curr]) {
            if (item.second != 0) {
                item.second--;
                ans.push_back(item.first);
                if (dfs(logger, ans, item.first, n)) {
                    return true;
                }
                ans.pop_back();
                item.second++;
            }
        }
        return false;
    }
};

// Eulerian path.
// Hierholzer's Algorithm implemented by greedy dfs.
// Building the route backwards when retreating.
// First keep going forward until you get stuck. That's a good main path already.
// Remaining tickets form cycles which are found on the way back and get merged into that main path.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> logger;
        for (auto& ticket : tickets) {
            logger[ticket[0]].insert(ticket[1]);
        }
        vector<string> ans;
        dfs(logger, ans, "JFK");
        return vector<string>(ans.rbegin(), ans.rend());
    }

private:
    void dfs(unordered_map<string, multiset<string>>& logger, vector<string>& ans, string curr) {
        while (!logger[curr].empty()) {
            string next = *logger[curr].begin();
            logger[curr].erase(logger[curr].begin());
            dfs(logger, ans, next);
        }
        ans.push_back(curr);
    }
};