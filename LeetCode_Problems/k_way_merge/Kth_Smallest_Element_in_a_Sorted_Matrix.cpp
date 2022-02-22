class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        
        vector<int> merge_pointers(num_rows, 0);
        
        priority_queue<int> pq;
        
        int num_rows_we_reached_end = 0;

        // K way merge        
        while(num_rows_we_reached_end < num_rows ) {
            
            int smallest_num = INT_MAX;
            int smallest_num_row;
            for(int row=0; row<num_rows; row++) {
                
                int current_col_ptr = merge_pointers[row];
                
                if(current_col_ptr < num_cols) {
                    if(matrix[row][current_col_ptr] < smallest_num) {
                        smallest_num = matrix[row][current_col_ptr];
                        smallest_num_row = row;
                    }
                }

            }
            
            merge_pointers[smallest_num_row]++;
            if(merge_pointers[smallest_num_row] >= num_cols) num_rows_we_reached_end++;
            
            pq.push(smallest_num);
            if(pq.size() == k) break;
        }
        
        return pq.top();
        
    }
};
