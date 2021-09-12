/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    class Compare
    {
    public:
        bool operator() (pair<double,int> a, pair<double,int> b)
        {
            return a.first > b.first;
        }
    };
    
    
    priority_queue<pair<double, int>, vector<pair<double, int>>, Compare> pq;

    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        vector<int> result;
        support_closestKValues(root, target);
        
        for(int i=0; i<k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
        
    }
    
    void support_closestKValues(TreeNode* root, double target) {
        
        if(root == nullptr) return;
        
        double delta = root->val - target;
        if(delta < 0) delta = -delta;
        
        pair<double, int> pq_element;
        
        pq_element.first = delta;
        pq_element.second = root->val;
        
        pq.push(pq_element);
        
        support_closestKValues(root->left, target);
        support_closestKValues(root->right, target);
        
    }
};
