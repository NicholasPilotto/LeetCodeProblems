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
    ListNode* removeNode(ListNode* node, int& n) {
      if (!node) {
        return nullptr;
      }

      if (node->next) {
        node->next = removeNode(node->next, n);
      }

      --n;

      if (n == 0) {
        return node->next;
      }

      return node;
    }

  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      return removeNode(head, n);
    }
};

void printList(ListNode* n) {
  if (!n) {
    return;
  }

  std::cout << n->val << '\n';

  printList(n->next);
}

int main() {
  ListNode* head = new ListNode(
    1, new ListNode(
      2, new ListNode(
        3, new ListNode(
          4, new ListNode(
            5, nullptr
          )
        )
      )
    )
  );

  Solution s;

  ListNode* n = s.removeNthFromEnd(head, 3);

  printList(n);

  return 0;
}
