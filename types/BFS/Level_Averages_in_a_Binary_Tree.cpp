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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> result;
    queue<TreeNode*> BST_queue;
    TreeNode* temp_node;
    double temp_sum;
    int num_elements_in_level;

    BST_queue.push(root);

    while(!BST_queue.empty()) {

      num_elements_in_level = BST_queue.size();

      temp_sum = 0;
      for(int i=0; i<num_elements_in_level; i++) {

        temp_node = BST_queue.front();
        BST_queue.pop();
        temp_sum += temp_node->val;

        if(temp_node->left != nullptr) BST_queue.push(temp_node->left);
        if(temp_node->right != nullptr) BST_queue.push(temp_node->right);

      }

      result.push_back(temp_sum / num_elements_in_level);

    }


    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}
