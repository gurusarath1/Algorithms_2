/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        
        char buf4[5];
        
        int num_chars_read = 0;
        
        while(num_chars_read < n) {
            
            int read_len = read4(buf4);
            
            if(read_len == 0) return num_chars_read;
            
            for(int i=0; i<read_len; i++) {
                buf[num_chars_read++] = buf4[i];
                
                if(num_chars_read >= n) break;
            }
            
        }
        
        return num_chars_read;
    }
};
