using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
 public:
  int start;
  int end;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class ConflictingAppointments {
 public:
  static bool canAttendAllAppointments(vector<Interval>& intervals) {

    sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.start < b.start; } );

    int start = intervals[0].start;
    int end = intervals[0].end;

    for(int i=1; i<intervals.size(); i++) {

      if(intervals[i].start < end) {
        return false;
      } else {
        start = intervals[i].start;
        end = intervals[i].end;
      }

    }

    return true;
  }
};
