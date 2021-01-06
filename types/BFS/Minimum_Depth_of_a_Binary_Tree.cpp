using namespace std;

#include <iostream>
#include <queue>

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

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    int minimumTreeDepth = 0;
    queue<TreeNode*> BST_queue;
    int num_elements_in_current_level = 0;
    int current_depth = 0;
    TreeNode* temp_node;

    BST_queue.push(root);

    while(!BST_queue.empty()) {

      current_depth += 1;
      num_elements_in_current_level = BST_queue.size();

      for(int i=0; i<num_elements_in_current_level; i++) {

        temp_node = BST_queue.front();
        BST_queue.pop();

        if(temp_node->left == nullptr && temp_node->right == nullptr) {
          return current_depth;
        }
        
        if(temp_node->left != nullptr) {
          BST_queue.push(temp_node->left);
        } 

        if(temp_node->right != nullptr) {
          BST_queue.push(temp_node->right);
        }

      }

    }
    
    return minimumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}
