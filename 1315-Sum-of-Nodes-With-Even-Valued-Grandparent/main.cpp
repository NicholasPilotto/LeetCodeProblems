#include <__config>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  static int calcSum(TreeNode* node, int& val) {
    if (!node) {
      return 0;
    }

    if (node->val % 2 == 0) {
      if (node->left && node->left->left) {
        val += node->left->left->val;
      }

      if (node->left && node->left->right) {
        val += node->left->right->val;
      }

      if (node->right && node->right->right) {
        val += node->right->right->val;
      }

      if (node->right && node->right->left) {
        val += node->right->left->val;
      }
    }

    calcSum(node->left, val);
    calcSum(node->right, val);

    return val;
  }

 public:
  static int sumEvenGrandparent(TreeNode* root) {
    int sum = 0;
    return calcSum(root, sum);
  }
};

int main() {
  auto* root = new TreeNode(
    6,
    new TreeNode(7, new TreeNode(2, new TreeNode(9), nullptr), new TreeNode(7, new TreeNode(1), new TreeNode(4))),
    new TreeNode(8, new TreeNode(1), new TreeNode(3, nullptr, new TreeNode(5))));

  std::cout << Solution::sumEvenGrandparent(root) << '\n';
  return 0;
}
