class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        map<char,int> letters_order_map;
        
        for(int i=0; i<order.size(); i++) {
            letters_order_map[order[i]] = i;
        }
        
        
        for(int i=1; i<words.size(); i++) {
            
            int w1_index = 0;
            int w2_index = 0;
            bool no_data_from_this_pair_of_words = false;
            
            // Search for the first letter mismatch
            while(words[i][w2_index] == words[i-1][w1_index]) {
                
                w1_index++;
                w2_index++;
                
                // Enter this when all the starting letters match
                if(w2_index >= words[i].size() || w1_index >= words[i-1].size()) {
                    
                    // Check if second word is small than first
                    if(words[i-1].size() > words[i].size()) return false;
                    
                    // Both strings are the same
                    no_data_from_this_pair_of_words = true;
                    break;
                }
            }
            
            if(no_data_from_this_pair_of_words) continue;
            
            // Check if the order is correct for the first mismatch letters
            if( letters_order_map[words[i-1][w1_index]] > letters_order_map[words[i][w2_index]] ) {
                return false;
            }
            
        }
        
        return true;
    }
};
