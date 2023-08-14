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

void printList(ListNode* l) {
  while (l) {
    cout << l->val;
    l = l->next;
  }
}

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum          = 0;
    int remainder    = 0;
    ListNode* result = nullptr;

    do {
      if (l1 && l2) {
        sum = l1->val + l2->val + remainder;
        l1  = l1->next;
        l2  = l2->next;
      } else if (l1) {
        sum = l1->val + remainder;
        l1  = l1->next;
      } else if (l2) {
        sum = l2->val + remainder;
        l2  = l2->next;
      }
      remainder = 0;

      if (sum >= 10) {
        remainder = 1;
        sum -= 10;
      }
      insertAtEnd(sum, result);
    } while (l1 || l2);

    if (remainder != 0) {
      insertAtEnd(1, result);
      remainder = 0;
    }

    return result;
  }

  void insertAtEnd(int data, ListNode*& head) {
    ListNode* newNode = new ListNode(data);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
};

int main() {
  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  Solution s;

  ListNode* result = s.addTwoNumbers(l1, l2);

  printList(result);

  return 0;
}
