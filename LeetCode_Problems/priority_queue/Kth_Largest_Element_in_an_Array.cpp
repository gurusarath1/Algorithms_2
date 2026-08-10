/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq;

        for(int i=0; i<nums.size(); i++) {
            pq.push(-nums[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        return -pq.top();
    }
};



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};
