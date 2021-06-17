class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        
        map< vector<int>, int > visited_states;
        map< int, vector<int>> visited_states_reverse;
        vector<int> current_state = cells;
        vector<int> next_state(cells.size());
        
        for(int i=0; i<n; i++) {
            
            if(visited_states.find(current_state) != visited_states.end()) {
                
                map< vector<int>, int >::iterator it = visited_states.find(current_state);
                
                int remaining_days = n - i;
                int cycle_len = i - it->second;
                remaining_days = remaining_days % cycle_len;
                
                return visited_states_reverse[it->second + remaining_days];
                
            }
            
            visited_states[current_state] = i;
            visited_states_reverse[i] = current_state;
            
            nextStartGenerator(current_state, next_state);
            current_state = next_state ;
        }
        
        return next_state;
    }
    
    void nextStartGenerator(vector<int> &state, vector<int> &next_state) {
        
        next_state[0] = 0;
        next_state[next_state.size() - 1] = 0;
        
        for(int i=1; i<state.size() - 1; i++) {
            if(state[i-1] == state[i+1]) {
                next_state[i] = 1;
            } else {
                next_state[i] = 0;
            }
        }
        
    }
};
