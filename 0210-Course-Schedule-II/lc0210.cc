// C++ solution.

// Kahn algorithm.
class Solution {
public:
    // adjacent table
    using graph = vector<vector<int>>;

    vector<int> findOrder(int num_courses, vector<vector<int>>& prerequisites) {
        graph directed_graph(num_courses);
        vector<int> indegree(num_courses, 0);
        buildGraph(directed_graph, indegree, num_courses, prerequisites);

        queue<int> que;
        for (int i = 0; i < num_courses; i++) {
            if (!indegree[i]) {
                que.push(i);
            }
        }

        vector<int> ans;
        while (!que.empty()) {
            int u = que.front();
            ans.push_back(u);
            que.pop();
            for (int v : directed_graph[u]) {
                if (--indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        if (ans.size() != num_courses) {
            return {};
        } else {
            return ans;
        }
    }

private:
    void buildGraph(graph& directed_graph, vector<int>& indegree,
                    const int num, const vector<vector<int>>& infos) {
        for (const auto& info : infos) {
            directed_graph[info.back()].push_back(info.front());
            ++indegree[info.front()];
        }
    }
};