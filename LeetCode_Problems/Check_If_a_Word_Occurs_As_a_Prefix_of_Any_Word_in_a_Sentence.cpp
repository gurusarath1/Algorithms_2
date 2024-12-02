class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int i = 0;
        int word_index = 1;
        for(char c : sentence) {
            if(c == ' ') {
                i = 0;
                word_index++;
                continue;
            }

            if(i < searchWord.size() && c == searchWord[i]) {
                i++;
                if(i == searchWord.size()) return word_index;
            } else {
                i=1000;
            }
        }
        
        return -1;
    }
};
