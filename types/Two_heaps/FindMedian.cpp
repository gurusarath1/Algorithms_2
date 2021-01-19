using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 public:

  priority_queue<int> first_half_max_queue;
  priority_queue<int> second_half_min_queue;

   void insertNum(int num) {

    // If both the queues are empty insert into the first max queue
    if(first_half_max_queue.size() == 0 && second_half_min_queue.size() == 0) {
      first_half_max_queue.push(num);
      return;
    }

    // Insert the number into one of the queue depending on the value of the number
    if(num < first_half_max_queue.top()) {
      first_half_max_queue.push(num);
    } else {
      second_half_min_queue.push(-num);
    }

    // Check if the queues are imbalanced and transfer the numbers to fix the imbalance
    if( ((int)first_half_max_queue.size() - (int)second_half_min_queue.size()) >= 2) {

      int number_to_transfer = first_half_max_queue.top();
      first_half_max_queue.pop();
      second_half_min_queue.push(-number_to_transfer);

    } else if ( ((int)second_half_min_queue.size() - (int)first_half_max_queue.size()) >= 2) {

      int number_to_transfer = -second_half_min_queue.top();
      second_half_min_queue.pop();
      first_half_max_queue.push(number_to_transfer);

    }


  }

   double findMedian() {

    if(first_half_max_queue.size() == second_half_min_queue.size()) {

      return ( (double)first_half_max_queue.top() + (double)(-second_half_min_queue.top()) ) / 2;

    } else if (first_half_max_queue.size() > second_half_min_queue.size()) {

      return first_half_max_queue.top();

    } else {

      return -second_half_min_queue.top();

    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
