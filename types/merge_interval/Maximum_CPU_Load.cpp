/*
We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. 
Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Job {
 public:
  int start = 0;
  int end = 0;
  int cpuLoad = 0;

  Job(int start, int end, int cpuLoad) {
    this->start = start;
    this->end = end;
    this->cpuLoad = cpuLoad;
  }
};



class MaximumCPULoad {
 public:

  struct comapreJobEndTime {

    bool operator() (const Job &a, const Job &b) {
      return a.end > b.end;
    }

  };

  static int findMaxCPULoad(vector<Job> &jobs) {
    int maxCPULoad = 0;
    int current_cpu_load = 0;

    priority_queue<Job, vector<Job>, comapreJobEndTime> JobEndTimeQueue;

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) { return a.start < b.start; } );


    for(int i=0; i<jobs.size(); i++) {

      while(!JobEndTimeQueue.empty() && JobEndTimeQueue.top().end < jobs[i].start) {
        current_cpu_load -= JobEndTimeQueue.top().cpuLoad;
        JobEndTimeQueue.pop();
      }

      JobEndTimeQueue.push(jobs[i]);
      current_cpu_load += jobs[i].cpuLoad;

      maxCPULoad = max(maxCPULoad, current_cpu_load);

    }


    return maxCPULoad;
  }
};

int main(int argc, char *argv[]) {
  vector<Job> input = {{0,2,3}, {1,3,5}, {1,5,1}, {4,5,10}, {6,7,10}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;
}
