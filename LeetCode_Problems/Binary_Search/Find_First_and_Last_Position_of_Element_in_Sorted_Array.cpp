class Solution {
public:

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


*/

    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{find_start(nums, target), find_end(nums, target)};
    }

    int find_start(vector<int>& num, int target) {
        int l = 0;
        int h = num.size() - 1;
        int ans = -1;

        while(l <= h) {
            int m = l + (h - l) / 2;

            if(num[m] == target) {
                h = m - 1;
                ans = m;
            } else if(num[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ans;
    }

    int find_end(vector<int>& num, int target) {
        int l = 0;
        int h = num.size() - 1;
        int ans = -1;

        while(l <= h) {
            int m = l + (h - l) / 2;

            if(num[m] == target) {
                l = m + 1;
                ans = m;
            } else if(num[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ans;
    }
};
