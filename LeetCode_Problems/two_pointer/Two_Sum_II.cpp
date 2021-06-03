class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int pointer1 = 0;
        int pointer2 = numbers.size() - 1;
        
        while(pointer1 != pointer2) {
            
            if(numbers[pointer1] + numbers[pointer2] > target) {
                pointer2--;
            } else if(numbers[pointer1] + numbers[pointer2] < target) {
                pointer1++;
            } else {
               break;
            }
            
        }
        
        return vector<int>{pointer1+1, pointer2+1}; // index is considered to start from 1
        
    }
};
