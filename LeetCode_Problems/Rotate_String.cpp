class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;
        if(s == goal) return true;

        s = s + s;

        int x = s.find(goal);

        if(x >= 0) return true;

        return false;
        
    }
};
