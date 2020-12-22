// C++ solution.

// Some notions:
// 1. Any connected graph without simple cycles is a tree.
// 2. Any connected graph who has n nodes with n-1 edges is a tree.
// 3. A leaf is a vertex of degree 1. An internal vertex is a vertex of degree at least 2.
// 4. The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


// Longest path.
// Idea: The root of an MHT has to be the middle point(s) of the longest path of the tree.
// Computing the longest path of a unrooted tree can be done in O(n) time by 2 tree traversals (dfs or bfs).
// 1. Randomly select a node x as start point, do a dfs/bfs to find the node y that has the longest distance from x.
// 2. Then y must be one of the endpoints on some longest path.
// 3. Let y the start point, and do another dfs/bfs. Find the node z that has the longest distance from y.
// 4. Now, the path from y to z is the longest one, and thus its middle point(s) is the answer.
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // structure of undirected graph, using adjacency list.
        vector<vector<int>> alst(n);
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            alst[x].push_back(y);
            alst[y].push_back(x);
        }

        // use an array to store the path.
        vector<int> prev(n, -1);

        // two tree traversals.
        int p1 = bfs(alst, 0, prev);
        fill(prev.begin(), prev.end(), -1);
        int p2 = bfs(alst, p1, prev);

        vector<int> path;
        while (p2 != p1) {
            path.push_back(p2);
            p2 = prev[p2];
        }
        path.push_back(p1);

        int path_len = path.size();
        vector<int> ans;
        ans.push_back(path[path_len/2]);
        // if the lenth of path is even, there are two middle points.
        if (path_len % 2 == 0) {
            ans.push_back(path[path_len/2 - 1]);
        }
        return ans;
    }

private:
    int bfs(vector<vector<int>>& alst, int start_point, vector<int>& prev) {
        queue<int> que;
        que.push(start_point);
        prev[start_point] = start_point;
        int end_point = start_point;
        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            for (int next : alst[curr]) {
                if (prev[next] == -1) {
                    que.push(next);
                    prev[next] = curr;
                }
            }
            end_point = curr;
        }
        return end_point;
    }
};


// Deleting leaf nodes.
// Idea: The idea is the same as the longest path one, we need to find the middle point(s) of the longest path.
//       The difference is that every time we delete all leaf nodes, until remaining <= 2 nodes.
//       The remaining node(s) should be the middle points.
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // structure of undirected graph, using adjacency list.
        vector<vector<int>> alst(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            alst[x].push_back(y);
            alst[y].push_back(x);
            degree[x]++;
            degree[y]++;
        }

        // kahn's algorithm
        int cnt = n;
        while (cnt > 2) {
            vector<int> deleted;
            for (int i = 0; i < n; i++) {
                if (degree[i] == 1) {
                    deleted.push_back(i);
                    degree[i] = -1;
                    cnt--;
                }
            }
            for (int node : deleted) {
                for (int prev : alst[node]) {
                    degree[prev]--;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1 || degree[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};