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

class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {
    
    ListNode* fast_ptr = head;
    ListNode* slow_ptr = head;

    if(head == nullptr) return true;

    // Find middle element
    while(fast_ptr != nullptr && fast_ptr->next != nullptr) {
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next->next;
    }

    // Reverse second half

    ListNode* current = slow_ptr;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while(current != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    // Check palindrome

    ListNode* ptr1 = head;
    ListNode* ptr2 = prev;

    while(ptr1 != nullptr && ptr2 != nullptr) {

      if(ptr1->value != ptr2->value) {
        return false;
      }

      ptr1 = ptr1->next;
      ptr2 = ptr2->next;

      if(ptr1 == nullptr && ptr2 == nullptr) {
        return true;
      }

    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}
