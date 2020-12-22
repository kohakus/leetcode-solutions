// C++ solution.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// simple DFS method.
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        vector<Node*>& neighbors = node->neighbors;
        Node* curr_copy = new Node(node->val);
        logger[node->val] = curr_copy;
        for (int i = 0; i < neighbors.size(); i++) {
            auto qurey = logger.find(neighbors[i]->val);
            if (qurey != logger.end()) {
                curr_copy->neighbors.push_back(qurey->second);
            } else {
                curr_copy->neighbors.push_back(cloneGraph(neighbors[i]));
            }
        }
        return curr_copy;
    }

private:
    std::unordered_map<int, Node*> logger;
};