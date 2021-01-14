/*
Given the head of a LinkedList and two positions ‘start_index’ and ‘end_index’, reverse the LinkedList from position ‘start_index’ to ‘end_index’.
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

class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int start_index, int end_index) {
    
    int current_index = 1; // index of un-processed node (not reversed)

    ListNode* current_node = head;
    ListNode* prev_node = nullptr;
    ListNode* next_node;

    // Move till the node from where we want to start reversing
    while(current_index != start_index) {
      next_node = current_node->next;
      prev_node = current_node;
      current_node = next_node;
      current_index++;
    }

    ListNode* last_non_reversed_node = prev_node;
    ListNode* last_node_of_reversed_section = current_node;

    // Start reversing the nodes
    prev_node = nullptr;
    while(current_index != end_index+1) {

      next_node = current_node->next;
      current_node->next = prev_node;
      prev_node = current_node;
      current_node = next_node;

      current_index++;
    }

    // complete the chain
    if(start_index != 1) {
      last_non_reversed_node->next = prev_node;
    }
    last_node_of_reversed_section->next = current_node;

    // Check if head of the linked list has changed
    if(start_index == 1){
      return prev_node;
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

  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
