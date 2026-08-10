/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int l = 0;
        int h = arr.size() - 1;

        while(l <= h) {
            int m = l + (h - l) / 2;

            if(arr[m] < x) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        // l - is the first element greater than x

        // Collect the k numbers with two pointers
        int ptr1 = l-1;
        int ptr2 = l;
        vector<int> ret;
        for(int i=0; i<k; i++) {

            if(ptr1 < arr.size() && ptr2 < arr.size()
               && ptr1 >= 0 && ptr2 >= 0) {

                int n1 = arr[ptr1];
                int n2 = arr[ptr2];

                if(abs(n1 - x) < abs(n2 - x)) {
                    ret.push_back(n1);
                    ptr1--;
                } else if(abs(n1 - x) > abs(n2 - x)) {
                    ret.push_back(n2);
                    ptr2++;
                } else if(n1 < n2) {
                    ret.push_back(n1);
                    ptr1--;
                } else {
                    ret.push_back(n2);
                    ptr2++;
                }

            } else if(ptr1 < arr.size() && ptr1 >= 0) {
                    int n1 = arr[ptr1];
                    ret.push_back(n1);
                    ptr1--;
            } else {
                    int n2 = arr[ptr2];
                    ret.push_back(n2);
                    ptr2++;
            }

        }

        sort(ret.begin(), ret.end()); // answer expected in sorted order

        return ret;
    }
};
