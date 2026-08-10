/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/

class Solution {
public:

    long long dist(int x, int y) {
        return x*x + y*y;
    }

    #define PQ_TYPE pair<long long, vector<int>>

    class Compare {
        public:
        bool operator()(PQ_TYPE &p1, PQ_TYPE &p2) const {
            return p1.first < p2.first;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<PQ_TYPE, vector<PQ_TYPE>, Compare > pq;

        for(vector<int> &point : points) {
            pq.push( PQ_TYPE{-dist(point[0], point[1]), point} );
        }

        vector<vector<int>> ret;
        for(int i=0; i<k; i++) {
            ret.push_back(pq.top().second);
            pq.pop();
        }

        return ret;
    }
};


class Solution {
public:

    long long dist(int x, int y) {
        return x*x + y*y;
    }

    #define PQ_TYPE pair<long long, vector<int>>

    class Compare {
        public:
        bool operator()(PQ_TYPE &p1, PQ_TYPE &p2) const {
            return p1.first < p2.first;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<PQ_TYPE, vector<PQ_TYPE>, Compare > pq;

        for(vector<int> &point : points) {
            pq.push( PQ_TYPE{dist(point[0], point[1]), point} );

            if(pq.size() > k) pq.pop(); // helps reducing the insertion time
        }

        vector<vector<int>> ret;
        for(int i=0; i<k; i++) {
            ret.push_back(pq.top().second);
            pq.pop();
        }

        return ret;
    }
};
