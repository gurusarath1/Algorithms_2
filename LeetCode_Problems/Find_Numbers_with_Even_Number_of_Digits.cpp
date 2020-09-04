/*
Given an array nums of integers, return how many of them contain an even number of digits.

Example 1:
Input: nums = [12,345,2,6,7896]
Output: 2
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        string s;
        int counter = 0;
        for(int numX : nums)
        {
            s = to_string(numX);
            if(s.size() % 2 == 0)
            {
                counter++;
            }
        }
        return counter;
    }
};
