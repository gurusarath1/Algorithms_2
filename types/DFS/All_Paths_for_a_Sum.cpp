/*
Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the sum of all the node values of each path equals ‘S’.
*/

using namespace std;

#include <iostream>
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

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> path;

    support_findPaths(root, sum, allPaths, path);

    return allPaths;
  }

  static void support_findPaths(TreeNode *root, int sum, vector<vector<int>> &allPaths, vector<int> path) {

    path.push_back(root->val);

    if(root->left == nullptr && root->right == nullptr) {
      if(sum - root->val == 0) {
        allPaths.push_back(path);
      }

      return;
    }

    if(root->left != nullptr) {
      support_findPaths(root->left, sum - root->val, allPaths, path);
    }

    if(root->right != nullptr) {
      support_findPaths(root->right, sum - root->val, allPaths, path);
    }

  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
