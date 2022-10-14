class Solution {
public:
    double average(vector<int>& salary) {
        
        double sum = 0;
        int lowest = INT_MAX;
        int highest = INT_MIN;
        for(int x : salary) {
            sum += x;
            
            if(x < lowest) lowest = x;
            if(x > highest) highest = x;
        }
        
        sum = sum - lowest - highest;
        
        return sum / (salary.size() - 2);
        
    }
};
