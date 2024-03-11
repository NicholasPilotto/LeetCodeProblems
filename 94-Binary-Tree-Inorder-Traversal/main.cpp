#include <__config>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    static vector<int> inorderTraversal(TreeNode* root) {
      TreeNode* current = root;
      vector<int> result;
      stack<TreeNode*> stack;

      while (!stack.empty() || current) {
        if (current) {
          stack.push(current);
          current = current->left;
        } else {
          current = stack.top();
          stack.pop();
          result.push_back(current->val);
          current = current->right;
        }
      }

      return result;
    }
};

int main() {
  TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

  vector<int> res = Solution::inorderTraversal(root);

  for (const int v : res) {
    std::cout << v << '\n';
  }
  return 0;
}
