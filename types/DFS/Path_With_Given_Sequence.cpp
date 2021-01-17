#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class PathWithGivenSequence {
 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {

    vector<int> curr_seq;

    return support_findPath(root, sequence, curr_seq);
  }

  static bool support_findPath(TreeNode *root, const vector<int> &sequence, vector<int> &current_sequence) {

    current_sequence.push_back(root->val);

    if(current_sequence == sequence) {
      return true;
    }

    if(root->left != nullptr) {

      if(support_findPath(root->left, sequence, current_sequence)) {
        return true;
      }

    }

    if(root->right != nullptr) {

      if(support_findPath(root->right, sequence, current_sequence)) {
        return true;
      }

    }

    current_sequence.erase(current_sequence.end() - 1);
    return false;
  }

};



int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
       << endl;
}
