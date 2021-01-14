/*
Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ sized sub-list starting from the head.
If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
*/

using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseEveryKElements {
 public:
  static ListNode *reverse(ListNode *head, int k) {

    ListNode* current_node = head;
    ListNode* next_node;
    ListNode* prev_node = nullptr;
    ListNode* first_node_in_current_k_set = nullptr;
    ListNode* first_node_in_prev_k_set = nullptr; // Last node of the set after reversal

    int k_set_number = 1;
    while(current_node != nullptr) {

      first_node_in_prev_k_set = first_node_in_current_k_set;
      first_node_in_current_k_set = current_node;
      prev_node = nullptr;
      for(int i=0; current_node != nullptr && i<k; i++) {

        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;

      }

      if(k_set_number == 1) {
        head = prev_node; // Update head in the first iteration
      } else {
        first_node_in_prev_k_set->next = prev_node; //link the prev part to the current part
      }

      k_set_number++;
    }

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = ReverseEveryKElements::reverse(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
