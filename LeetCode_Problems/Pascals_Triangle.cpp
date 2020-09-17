/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> PascalsTriangle;
        vector<int> first_row;
        first_row.push_back(1);
        vector<int> current_row = first_row;
        
        for(int i=0; i<numRows; i++) {
            PascalsTriangle.push_back(current_row);
            current_row = generateNextRow(current_row);
        }
        
        return PascalsTriangle;
    }
    
    vector<int> generateNextRow(vector<int>& in_row) {
        
        vector<int> next_row;
        next_row.push_back(1);
        for(int i=0; i<in_row.size()-1; i++) {
            next_row.push_back(in_row[i] + in_row[i+1]);
        }
        
        next_row.push_back(1);
        return next_row;
        
    }
};
