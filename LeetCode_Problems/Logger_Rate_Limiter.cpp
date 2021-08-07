class Logger {
public:
    /** Initialize your data structure here. */
    
    map<string, int> messTims;
    
    Logger() {
        //
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        
        if(messTims.find(message) == messTims.end()) {
            messTims[message] = timestamp;
            return true;
        } else {
            if(messTims[message] + 10 <= timestamp) {
                messTims[message] = timestamp;
                return true;
            } else {
                return false;
            }
        }
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
