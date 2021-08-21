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
    
    map<Node*,Node*> visited;
    
    Node* cloneGraph(Node* node) {
        return traverse(node);
    }
    
    Node* traverse(Node* node) {
        
        if(node == nullptr) return nullptr;
        
        Node* new_node = new Node(node->val);
        visited[node] = new_node;
        
        for(int i=0; i<(node->neighbors).size(); i++) {
            
            if(visited.find((node->neighbors)[i]) == visited.end()) {
                Node* _n = traverse((node->neighbors)[i]);
                if(_n != nullptr) new_node->neighbors.push_back(_n);
            } else {
                (new_node->neighbors).push_back( visited[(node->neighbors)[i]] );
            }
            
        }
        
        return new_node;
    }
};
