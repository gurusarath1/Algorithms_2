/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        map<int,int> mapX;
        
        for(int i=0; i<nums.size(); i++) {
            mapX[nums[i]] = 1;
        }

        for(int i=0; i<nums.size()+1; i++) {
            if(mapX.find(i) == mapX.end()) {
                return i;
            }
        }
        
        return 0;
    }
};
