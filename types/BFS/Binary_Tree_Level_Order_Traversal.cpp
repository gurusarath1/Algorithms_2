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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;

    queue<TreeNode*> BFS_queue;
    TreeNode *current_node;
    int level_size;

    BFS_queue.push(root);

    while(!BFS_queue.empty()) {

      level_size = BFS_queue.size();
      vector<int> current_level;

      for(int i=0; i<level_size; i++) {

        current_node = BFS_queue.front();
        BFS_queue.pop();
        current_level.push_back(current_node->val);

        if(current_node->left != nullptr) {
          BFS_queue.push(current_node->left);
        }

        if(current_node->right != nullptr) {
          BFS_queue.push(current_node->right);
        }

      }

      result.push_back(current_level);

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
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
