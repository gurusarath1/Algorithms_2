/*
Given an integer array nums sorted in non-decreasing order and an integer target, return true if target is a majority element, or false otherwise.

A majority element in an array nums is an element that appears more than nums.length / 2 times in the array.
*/

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {

        int first_occ = -1;
        int last_occ = -1;
        int thres = nums.size() / 2;

        int l=0;
        int h=nums.size() - 1;

        while(l <= h) {
            int m = l + (h - l) / 2;

            if(nums[m] == target) {
                first_occ = m;
                h = m - 1;
            } else if(nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        if(first_occ == -1) return false;

        l = 0;
        h = nums.size() - 1;
        while(l <= h) {
            int m = l + (h - l) / 2;

            if(nums[m] == target) {
                last_occ = m;
                l = m + 1;
            } else if(nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        int num_occ = last_occ - first_occ + 1;

        if(num_occ > thres) {
            return true;
        }
        
        return false;
    }
};
