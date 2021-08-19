/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        set<Node*> visited;
        Node* node = p;
        
        while(node != nullptr) {
            visited.insert(node);
            node = node->parent;
        }
        
        node = q;
        while(node != nullptr) {
            
            if(visited.find(node) != visited.end()) {
                return node;
            }
            
            node = node->parent;
        }
        
        return nullptr;
    }
};
