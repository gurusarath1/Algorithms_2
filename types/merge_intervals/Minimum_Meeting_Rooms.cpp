/*
Given a list of intervals representing the start and end time of ‘N’ meetings, find the minimum number of rooms required to hold all the meetings.
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    int min_num_meeting_rooms_required = 0;
    priority_queue<int> end_time_queue;  // This is a maxheap by default; But we  will use it as a min heap

    sort(meetings.begin(), meetings.end(), [](Meeting &a, Meeting &b) {return a.start < b.start; } );

    for(int i=0; i<meetings.size(); i++) {

      while(!end_time_queue.empty() && -end_time_queue.top() <= meetings[i].start) {
        // Remove all events that has ended
        end_time_queue.pop();
      }

      end_time_queue.push(-meetings[i].end);

      if(end_time_queue.size() > min_num_meeting_rooms_required) {
        min_num_meeting_rooms_required = end_time_queue.size(); // Number of evenet that are currently happening now
      }

    }

    return min_num_meeting_rooms_required;
  }
};

int main(int argc, char *argv[]) {
  vector<Meeting> input = { {1,2}, {2,3}, {3,8}, {3,5}, {5,6}, {5,7}, {6,8}, {6,10} };  // 4
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

}
