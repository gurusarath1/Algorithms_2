class Solution {
public:
    int maximumSwap(int num) {


        // Step 1: Get the digits
        int num_ = num;
        vector<int> digits;
        while(num_) {
            int digit = num_ % 10;
            num_ /= 10;
            digits.push_back(digit);
        }

        // Step 2: get the max digit to the right
        // .first = max digit to right 
        // .second = index of max digit
        vector<pair<int,int>> right_max(digits.size());
        int right_max_current = INT_MIN;
        int right_max_index = -1;
        for(int i=0; i < digits.size(); i++) {
            if(right_max_current < digits[i]) {
                right_max_current = digits[i];
                right_max_index = i;
            }
            right_max[i] = pair<int,int> {right_max_current, right_max_index};
        }

        // Step 3: find the digits to swap and swap them
        for(int i=digits.size()-1; i >= 0; i--) {
            
            // swap condition
            if(digits[i] < right_max[i].first) {
                int temp = digits[i];
                digits[i] = digits[right_max[i].second];
                digits[right_max[i].second] = temp;
                break;
            }
        }

        // Step 4: create the number from array
        int ans = 0;
        int power = 1;
        for(int i=0; i<digits.size(); i++) {
            ans += digits[i] * power;
            power *= 10;
        }

        return ans;
    }
};
