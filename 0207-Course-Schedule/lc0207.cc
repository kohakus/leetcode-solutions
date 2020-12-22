// C++ solution.

// simple Kahn algorithm.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph directedGraph(numCourses);
        vector<int> indegree(numCourses, 0);
        buildGraph(directedGraph, indegree, numCourses, prerequisites);

        queue<int> tempque;
        int cnt = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) { tempque.push(i); }
        }

        while (!tempque.empty()) {
            int u = tempque.front();
            tempque.pop();
            ++cnt;
            for (int v : directedGraph[u]) {
                if (--indegree[v] == 0) {
                    tempque.push(v);
                }
            }
        }
        return cnt == numCourses;
    }
private:
    // let graph an adjacent table
    using graph = vector<vector<int>>;

    static void buildGraph(graph& directedGraph, vector<int>& indegree, const int numNode, const vector<vector<int>>& edges) {
        for (const auto& edge : edges) {
            directedGraph[edge.back()].push_back(edge.front());
            ++indegree[edge.front()];
        }
    }
};