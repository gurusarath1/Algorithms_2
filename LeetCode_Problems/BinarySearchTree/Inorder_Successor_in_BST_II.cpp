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
    Node* inorderSuccessor(Node* node) {
        
        Node* current_node;
        Node* prev_node;
        
        if(node == nullptr) return nullptr;
        
        // Node has a right
        if(node->right != nullptr) {
            
            current_node = node->right;
            prev_node = nullptr;
            while(current_node != nullptr) {
                prev_node = current_node;
                current_node = current_node->left;
            }

            return prev_node;
            
        } else {
                        
            // No right tree
            current_node = node;
            prev_node = nullptr;
            while(current_node->parent != nullptr) {
                
                prev_node = current_node;
                current_node = current_node->parent;
                
                if(prev_node == current_node->left) {
                    return current_node;
                }
                
            }
            
        }

        return nullptr;
        
    }
};
