class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s.size() != goal.size()) return false;

        if(s != goal) {

            int idx_1 = -1;
            int idx_2 = -1;
            for(int i=0; i<s.size(); i++) {
                if(s[i] != goal[i]) {
                    if(idx_1 == -1) idx_1 = i;
                    else if(idx_2 == -1) idx_2 = i;
                    else return false;
                }
            }

            if(idx_1 == -1 || idx_2 == -1) return false;
            if(s[idx_1] == goal[idx_2] && goal[idx_1] == s[idx_2]) {
                return true;
            } else {
                return false;
            }
        } else {

            map<char, int> m;

            for(int i=0; i<s.size(); i++) {
                
                if(m.find(s[i]) == m.end()) {
                    m[s[i]] = 0;
                }

                m[s[i]] += 1;

                if(m[s[i]] == 2) return true;  
            }

        }


        return false;
        
    }
};
