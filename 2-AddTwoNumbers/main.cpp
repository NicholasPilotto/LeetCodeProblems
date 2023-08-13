#include <iostream>

using std::cout;

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;

  ListNode() :
    val(0),
    next(nullptr) {}

  ListNode(int x) :
    val(x),
    next(nullptr) {}

  ListNode(int x, ListNode* next) :
    val(x),
    next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    int remainder = 0;
    ListNode* tmpResult = new ListNode();
    ListNode* result = tmpResult;
    while (l1) {
      sum = l1->val + l2->val + remainder;
      remainder = 0;

      if (sum >= 10) {
        remainder = 1;
        sum -= 10;
      }

      tmpResult->val = sum;
      tmpResult = tmpResult->next;
      tmpResult = new ListNode();

      l1 = l1->next;
      l2 = l2->next;
    }

    if (remainder != 0) {
      tmpResult = new ListNode(remainder);
      remainder = 0;
      tmpResult = tmpResult->next;
    }

    return result;
  }
};

void printList(ListNode* l) {
  while(l) {
    cout << l->val;
    l = l->next;
  }
}

int main() {
  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  Solution s;

  ListNode* result = s.addTwoNumbers(l1, l2);

  cout << result << " " << l2 << "\n";

  printList(result);

  return 0;
}
