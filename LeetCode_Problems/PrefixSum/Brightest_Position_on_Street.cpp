/*
TIME LIMIT EXCEEDED !!!!!!!!
*/


class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        
        int start_of_number_line = 0;
        int end_of_number_line = 0;
        
        for(vector<int> light : lights) {
            int start_index = light[0] - light[1];
            int end_index = light[0] + light[1];
            
            if(start_index < start_of_number_line) start_of_number_line = start_index;
            if(end_index > end_of_number_line) end_of_number_line = end_index;
        }
        
        vector<int> number_line(end_of_number_line - start_of_number_line + 1, 0);
       
        for(vector<int> light : lights) {
            int start_index = light[0] - light[1] - start_of_number_line;
            int end_index = light[0] + light[1] - start_of_number_line;
            
            number_line[start_index] += 1;
            if(end_index+1 < number_line.size()) number_line[end_index+1] -= 1;
        }
        
        for(int i=1; i<number_line.size(); i++) {
            number_line[i] = number_line[i] + number_line[i-1];
        }
        
        int brightest = 0;
        int index = 0;
        for(int i=0; i<number_line.size(); i++) {
            if(number_line[i] > brightest) {
                brightest = number_line[i];
                index = i;
            }
        }
        
        return index + start_of_number_line;
        
    }
};
