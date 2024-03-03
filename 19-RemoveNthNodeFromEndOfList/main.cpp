#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  private:
    ListNode* revertList(ListNode* node) {
      if (!node) {
        return nullptr;
      }

      ListNode* newNode = new ListNode(node->val, node);
    }

  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    }
};

int main() {
  return 0;
}
