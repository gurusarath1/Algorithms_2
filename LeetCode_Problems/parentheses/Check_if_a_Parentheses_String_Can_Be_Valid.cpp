class Solution {
public:
    bool canBeValid(string s, string locked) {

        if(s.size() & 1) return false; // Odd string cannot be balanced

        int open = 0;
        int close = 0;
        int unlocked = 0;

        // Left to right pass
        for(int i=0; i<s.size(); i++) {

            if(locked[i] == '0') {
                unlocked++;
            } else if(s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if(!((unlocked + open) >= close)) { // Closing balance check
                return false;
            }
        }

        open = 0;
        close = 0;
        unlocked = 0;
        // Right to left pass
        for(int i=s.size()-1; i>=0; i--) {

            if(locked[i] == '0') {
                unlocked++;
            } else if(s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if(!((unlocked + close) >= open)) { // Opening balance check
                return false;
            }
        }

        return true;
    }
};
