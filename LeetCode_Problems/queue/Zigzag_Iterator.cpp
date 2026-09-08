/*
Given two vectors of integers v1 and v2, implement an iterator to return their elements alternately.

Implement the ZigzagIterator class:

ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two vectors v1 and v2.
boolean hasNext() returns true if the iterator still has elements, and false otherwise.
int next() returns the current element of the iterator and moves the iterator to the next element.
*/

class ZigzagIterator {
public:

    int j = 0;
    int sz = 0;
    queue<int> q;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        sz = v1.size() + v2.size();
        int i1 = 0, i2 = 0;

        for(int i=0; i<sz; i++) {
            if( (i & 1) == 0) {
                if(i1 < v1.size()) {
                    q.push(v1[i1]);
                    i1++;
                } else {
                    q.push(v2[i2]);
                    i2++;
                }
            } else {
                if(i2 < v2.size()) {
                    q.push(v2[i2]);
                    i2++;
                } else {
                    q.push(v1[i1]);
                    i1++;
                }
            }
        }
        
    }

    int next() {
        int val = q.front();
        q.pop();
        j++;
        return val;
    }

    bool hasNext() {
        if(j < sz) {
            return true;
        }

        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
