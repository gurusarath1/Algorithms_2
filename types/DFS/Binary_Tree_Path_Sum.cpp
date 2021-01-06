/*
Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ‘S’.
*/

using namespace std;

#include <iostream>

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

class TreePathSum {
 public:
  static bool hasPath(TreeNode *root, int sum) {
    
    if(root->left == nullptr && root->right == nullptr) {
      if(sum - root->val == 0) {
        return true;
      } else {
        return false;
      }
    }

    bool path_1 = false;
    if(root->left != nullptr) {
      path_1 = hasPath(root->left, sum - root->val);
    }

    if(path_1) return path_1;
    
    bool path_2 = false;
    if(root->right != nullptr) {
      path_2 = hasPath(root->right, sum - root->val);
    }

    if(path_2) return path_2;

    return false;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
  cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;
}
