class Solution {
public:
    int getSum(int a, int b) {

        int sum = a;
        int carry = b;

        while(carry != 0) {
            int sum_next = sum ^ carry;
            carry = (sum & carry) << 1;
            sum = sum_next;
        }

        return sum;
    }
};
