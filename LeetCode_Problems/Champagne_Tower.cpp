class Solution {
public:
    // TIME LIMIT EXCEEDS
    map<pair<int,int>, double> quantity_memo;
    
    double champagneTower(int poured, int query_row, int query_glass) {
        
        support_champagneTower(poured, 0, 0, query_row + 1);
        
        return quantity_memo[{query_row, query_glass}];
        
    }
    
    
    void support_champagneTower(double current_quantity, int row, int glass, int target_row) {
        
        if(row >= target_row) {
            return;
        }
        
        current_quantity = quantity_memo[{row, glass}] + current_quantity;
        
        if(current_quantity <= 1) {
            quantity_memo[{row, glass}] = current_quantity;
            return;
        } else {
            quantity_memo[{row, glass}] = 1;
            current_quantity = current_quantity - 1;
            support_champagneTower(current_quantity/2, row+1, glass, target_row);
            support_champagneTower(current_quantity/2, row+1, glass+1, target_row);
        }
        
    }
    
};
