// C++ solution.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Time: O(N), Space O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) { return nullptr; }
        if (copy_table.find(head) != copy_table.end()) {
            return copy_table[head];
        }

        Node* copy_head = new Node(head->val);
        copy_table[head] = copy_head;

        copy_head->next = copyRandomList(head->next);
        copy_head->random = copyRandomList(head->random);
        return copy_head;
    }
private:
    unordered_map<Node*, Node*> copy_table;
};

// Time: O(N), Space: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *copy_head, *l1, *l2;
        if (head == nullptr) { return nullptr; }

        for (l1 = head; l1 != nullptr; l1 = l1->next) {
            l2 = new Node(l1->val);
            l2->next = l1->random;
            l1->random = l2;
        }

        for (l1 = head; l1 != nullptr; l1 = l1->next) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : nullptr;
        }

        copy_head = head->random;
        for (l1 = head; l1 != nullptr; l1 = l1->next) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : nullptr;
        }
        return copy_head;
    }
};