/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<int> result;
    
    vector<int> postorder(Node* root) {
        
        recurse(root);
        
        return result;
        
    }
    
    void recurse(Node* node) {
        
        if(node == nullptr) return;
        
        for(Node* child : node->children) {
            recurse(child);
        }
        
        result.push_back(node->val);
    }
    
    
};
