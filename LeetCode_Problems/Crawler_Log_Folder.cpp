class Solution {
public:
    int minOperations(vector<string>& logs) {

        unsigned int num_steps = 0;

        for(string &op : logs) {
            if(op[0] == '.' && op[1] == '.') {
                if(num_steps != 0) num_steps--;
            } else if (op[0] == '.' && op[1] == '/') {
                continue;
            } else {
                num_steps++;
            }
        }
        
        return num_steps;
    }
};
