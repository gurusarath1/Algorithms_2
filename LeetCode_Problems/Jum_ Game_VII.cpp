/*
You are given a 0-indexed binary string s and two integers minJump and maxJump.
In the beginning, you are standing at index 0, which is equal to '0'. 
You can move from index i to index j if the following conditions are fulfilled:

    i + minJump <= j <= min(i + maxJump, s.length - 1), and
    s[j] == '0'.

Return true if you can reach index s.length - 1 in s, or false otherwise.
*/

// Time limit exceded soln

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        return canReach_support(s, minJump, maxJump, 0);
    }
    
    bool canReach_support(string& s, int minJump, int maxJump, int current_index) {
        
        if(current_index == s.size() - 1) {
            return true;
        }
        
        for(int i=minJump; i<=maxJump; i++) {
            
            if(current_index + i < s.size() && s[current_index + i] == '0') {
                if(canReach_support(s, minJump, maxJump, current_index + i)) {
                    return true;
                }
            } 
            
        }
        
        return false;
    }
};
