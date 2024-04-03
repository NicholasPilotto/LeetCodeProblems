#include <cstddef>
#include <iostream>
#include <new>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
    static bool isSameTree(TreeNode* p, TreeNode* q) {
      if (!p && q) {
        return false;
      }

      if (p && !q) {
        return false;
      }

      if (!p && !q) {
        return true;
      }

      bool lh = isSameTree(p->left, q->left);

      if (!lh) {
        return false;
      }

      bool rh = isSameTree(p->right, q->right);

      if (!rh) {
        return false;
      }

      return p->val == q->val;
    }
};

int main() {

  TreeNode* p = new TreeNode(1, new TreeNode(2), nullptr);
  TreeNode* q = new TreeNode(1, nullptr, new TreeNode(2));

  std::cout << Solution::isSameTree(p, q) << '\n';
  return 0;
}
