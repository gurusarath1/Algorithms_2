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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> result;
        queue<Node*> q;
        
        if(root == nullptr) return result;
        
        q.push(root);
        
        result.push_back({root->val});
        
        while(!q.empty()) {
            
            vector<int> current_level;
            current_level.clear();
            
            int current_level_size = q.size();

            for(int i=0; i<current_level_size; i++) {
                Node* current_node = q.front();
                q.pop();
            
                for(int j=0; j<(current_node->children).size(); j++) {
                    q.push( (current_node->children)[j] );
                    current_level.push_back( ((current_node->children)[j])->val );
                }
                
            }
            
            if(current_level.size() > 0) result.push_back(current_level);
            
        }
        
        return result;
        
    }
};
