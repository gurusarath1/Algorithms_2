/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
*/

class MovingAverage {
public:

    deque<int> dq;
    int sz;

    MovingAverage(int size) {
        sz = size;
    }
    
    double next(int val) {

        dq.push_back(val);

        if(dq.size() > sz) {
            dq.pop_front();
        }

        double sum = 0;
        for(int i=0; i<dq.size(); i++) {
            sum += dq[i];
        }

        return sum / dq.size();
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
