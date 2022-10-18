class Solution {
public:
    string interpret(string command) {
        
        string result = "";
        
        for(int i=0; i<command.size(); i++) {
            
            if(command[i] == 'G') {
                
                result += 'G';
                
            } else if(command[i] == '(') {
                
                if(command[i+1] == 'a') {
                    result += "al";
                    i += 2;
                } else {
                    result += "o";
                }
                
            }
            
        }
        
        return result;
        
    }
};
