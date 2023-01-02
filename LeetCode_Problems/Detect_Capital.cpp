class Solution {
public:
    bool detectCapitalUse(string word) {

        if(word.size() == 1) return true;

        if(word[0] >= 'a' && word[0] <= 'z') {

            for(char c : word) {
                if( !(c >= 'a' && c <= 'z') ) {
                    return false;
                }
            }

        } else if(word[0] >= 'A' && word[0] <= 'Z') {

            if(word[1] >= 'a' && word[1] <= 'z') {

                for(int i=2; i<word.size(); i++) {
                    if( !(word[i] >= 'a' && word[i] <= 'z') ) return false;
                }

            } else {

                for(int i=2; i<word.size(); i++) {
                    if( !(word[i] >= 'A' && word[i] <= 'Z') ) return false;
                }

            }
        }

        return true;        
    }
};
