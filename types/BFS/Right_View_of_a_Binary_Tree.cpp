/*
Given a binary tree, return an array containing nodes in its right view. The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.
*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class RightViewTree {
 public:
  static vector<TreeNode *> traverse(TreeNode *root) {
    vector<TreeNode *> result;
    queue<TreeNode*> BST_queue;
    int num_nodes_in_level;
    TreeNode* temp_node;

    BST_queue.push(root);

    while(!BST_queue.empty()) {

      num_nodes_in_level = BST_queue.size();

      for(int i=0; i<num_nodes_in_level; i++) {

        temp_node = BST_queue.front();
        BST_queue.pop();

        if(i == num_nodes_in_level - 1) {
          result.push_back(temp_node);
        }

        if(temp_node->left != nullptr) {

          BST_queue.push(temp_node->left);

        }

        if(temp_node->right != nullptr) {

          BST_queue.push(temp_node->right);

        }

      }

    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->left->left->left = new TreeNode(3);
  vector<TreeNode *> result = RightViewTree::traverse(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
}
