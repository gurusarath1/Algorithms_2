/*
You are given a 0-indexed binary string s and two integers minJump and maxJump.
In the beginning, you are standing at index 0, which is equal to '0'. 
You can move from index i to index j if the following conditions are fulfilled:

    i + minJump <= j <= min(i + maxJump, s.length - 1), and
    s[j] == '0'.

Return true if you can reach index s.length - 1 in s, or false otherwise.

*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int current_index;
        queue<int> q;
        int n= s.size() - 1;
        int max_reach = 0;
        
        q.push(0);
        
        while(!q.empty()) {
            
            current_index = q.front();
            q.pop();
            
            if(current_index == n) return true;
            
            for(int i=max(minJump+current_index, max_reach); i<=min(maxJump+current_index, n); i++) {
                
                if(s[i] == '0') {
                    q.push(i);
                }
                
            }
            
            max_reach = maxJump + current_index; // Do not add already added indices
            
        }
        
        return false;
        
    }
};
