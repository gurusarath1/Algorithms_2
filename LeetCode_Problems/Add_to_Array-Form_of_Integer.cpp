class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        vector<int> result;
        
        int current_digit;
        int c = 0;
        for(int i=num.size()-1; i >= 0 || k != 0; i--) {
            
            current_digit = k%10;
            k = k/10;
            
            int sum;
            
            if(i >= 0) {
                sum = current_digit + num[i] + c;
            } else {
                sum = current_digit + c;
            }
            
            if(sum > 9) {
                c = 1;
                result.push_back(sum % 10);
            } else {
                c = 0;
                result.push_back(sum);
            }
        }
        
        if(c == 1) {
            result.push_back(1);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};
