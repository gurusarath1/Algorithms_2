using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
 public:
  static vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> mergedIntervals;
    Interval current_interval(0,0);
    int start, end;


    // Sort the list of intervals based on the start times
    sort(intervals.begin(), 
            intervals.end(), 
              [](Interval &x, Interval &y) { return x.start < y.start; } );



    vector<Interval>::iterator itr = intervals.begin();
    start = (*itr).start;
    end = (*itr).end;
    itr++; 
    while(itr != intervals.end()) {

      current_interval = *itr;

      if(current_interval.start < end) { // Overlapping intevals

        end = max(current_interval.end, end);

      } else { // Broken intervals

        mergedIntervals.push_back({start,end}); // Push the connected interval

        start = current_interval.start; // Start from the next interval
        end = current_interval.end;

      }

      itr++;

    }


    mergedIntervals.push_back({start,end});

    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
