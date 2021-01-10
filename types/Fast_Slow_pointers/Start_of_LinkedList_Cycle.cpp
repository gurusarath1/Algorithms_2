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

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
  
    /*
    1 - Find the length of the Loop (say M).
    2 - Reset the fast and slow pointers to the head node.
    3 - Move the fast pointer M steps.
    4 - Move both fast and slow pointers 1 step at a time until they meet.
    5 - The point at which they meet is the start of the loop
    */
  
    
    // FIND THE LENGTH OF THE LOOP
    int length_of_loop = 1;
    ListNode *slow_pointer = head;
    ListNode *fast_pointer = head;
    
    while(fast_pointer->next && fast_pointer->next->next) {

      fast_pointer = fast_pointer->next->next;
      slow_pointer = slow_pointer->next;

      if(fast_pointer == slow_pointer) {
        break;
      }
    }

    fast_pointer = fast_pointer->next;
    while(fast_pointer != slow_pointer) {
      fast_pointer = fast_pointer->next;
      length_of_loop++;
    }

    // MOVE THE FAST POINTER length_of_loop TIMES
    slow_pointer = head;
    fast_pointer = head;
    for(int i=0; i<length_of_loop; i++) {
      fast_pointer = fast_pointer->next;
    }

    // MOVE BOTH POINTERS 1 STEP AT A TIME UNTIL THEY MEET
    while(fast_pointer != slow_pointer) {
      fast_pointer = fast_pointer->next;
      slow_pointer = slow_pointer->next;
    }

    return fast_pointer;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
}
