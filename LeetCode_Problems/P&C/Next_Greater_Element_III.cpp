/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n.
If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int num = n;

        if(num == INT_MAX) return -1;

        while(num > 0) {
            int digit = num % 10;
            digits.push_back(digit);
            num = num / 10;
        }

        reverse(digits.begin(), digits.end());

        long long ans = 0;
        for(int i=digits.size()-2; i>=0; i--) {

            if(digits[i+1] > digits[i]) { // first decreasing digit

                // Find the first digit from right just greater than digits[i]
                // i is prefix end point
                int idx_num_just_greater_than_i = INT_MAX;
                for(int j=digits.size()-1; j>=i+1; j--) { 
                    if(digits[j] > digits[i]) {
                        idx_num_just_greater_than_i = j;
                        break;
                    }
                }

                swap(digits[i], digits[idx_num_just_greater_than_i]);
                reverse(digits.begin() + i + 1, digits.end()); // smalles possible suffix

                for(int n : digits) {
                    ans *= 10;
                    ans += n;
                }

                if(ans > INT_MAX) return -1;

                return ans;
            }
        }

        return -1;
    }
};
