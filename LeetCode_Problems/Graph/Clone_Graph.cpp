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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        map<Node*, Node*> map_old_new_nodes;
        return traverse(node, map_old_new_nodes);
    }
    
    Node* traverse(Node* current_node, map<Node*, Node*> &visited) {
        
        if(current_node == nullptr) return nullptr;
        
        if(visited.find(current_node) != visited.end()) {
            return visited[current_node];
        }
        
        Node* new_node = new Node(current_node->val);
        visited[current_node] = new_node;
        
        for(Node* node_ptr : current_node->neighbors) {
            new_node->neighbors.push_back( traverse(node_ptr, visited) );
        }
        
        return new_node;
    }
    
    
};
