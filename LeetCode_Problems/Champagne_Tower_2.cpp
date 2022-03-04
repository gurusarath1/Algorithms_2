class Solution {
public:
    
    double quantity[101][101];
    
    double champagneTower(int poured, int query_row, int query_glass) {
        
        quantity[0][0] = poured;
        
        for(int row=0; row<=query_row; row++) {
            
            for(int glass=0; glass <= row; glass++) {
                
                double pored_into_current_glass = quantity[row][glass];
                if(pored_into_current_glass > 1) {
                    double flows_out_of_current_glass_on_one_side = (pored_into_current_glass - 1) / 2;
                    
                    quantity[row][glass] = 1;
                    
                    quantity[row+1][glass] += flows_out_of_current_glass_on_one_side;
                    quantity[row+1][glass+1] += flows_out_of_current_glass_on_one_side;
                    
                } else {
                    ;
                }
                
            }
            
        }
        
        return quantity[query_row][query_glass];
        
    }
    
};
