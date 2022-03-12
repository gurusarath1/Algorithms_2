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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> visited;
        return recurse(head, visited);
    }
    
    Node* recurse(Node*  current_node, map<Node*, Node*>& visited) {
        
        if(current_node == NULL) return NULL;
        
        if(visited.find(current_node) != visited.end()) {
            return visited[current_node];
        }
        
        Node* new_node = new Node(current_node->val);
        visited[current_node] = new_node;
        
        new_node->next = recurse(current_node->next, visited);
        new_node->random = recurse(current_node->random, visited);
    
        return new_node;
    }
};
