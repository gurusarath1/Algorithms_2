class Solution {
public:
    string compressedString(string word) {

        char curr = ' ';
        char counter = '0';
        string res= "";
        for(int i=0; i<word.size()+1; i++) {

            if(i == word.size()) {
                if(counter != '0') {
                    res += counter;
                    res += curr;
                }
                break;
            }

            char c = word[i];

            if(c != curr) {

                if(curr != ' ' && counter != '0') {
                    res += counter;
                    res += curr;
                }
    
                counter = '1';
                curr = c;
            } else {
                counter += 1;
                if(counter == '9') {
                    res += counter;
                    res += curr;
                    counter = '0';
                }
            }

        }

        return res;
        
    }
};
