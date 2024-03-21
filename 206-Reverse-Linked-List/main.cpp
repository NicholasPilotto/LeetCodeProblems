#include <__config>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static void printList(ListNode* node) {
      if (!node) {
        return;
      }

      std::cout << node->val << '\n';
      printList(node->next);
    }
};

class Solution {
  public:
    static ListNode* reverseList(ListNode* head) {
      ListNode* node = head;
      ListNode* tmp = nullptr;
      ListNode* next = nullptr;
      while (node) {
          next = node->next;
          node->next = tmp;
          tmp = node;
          node = next;
      }

      return head = tmp;
    }
};

int main() {
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

  ListNode* node = Solution::reverseList(head);

  ListNode::printList(node);
  return 0;
}
