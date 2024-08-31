class Solution {
public:

    bool is_vowel(char c) {

        switch(c) {

            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                return true;
            default:
                return false;
        }

        return false;
    }

    int maxVowels(string s, int k) {

        int current_num_vowels = 0;
        int max_num_vowels = 0;

        int ptr1 = 0;
        int ptr2 = 0;

        while(ptr2 < s.size() + 1) {

            if(ptr2 < k) {
                if( is_vowel(s[ptr2]) ) {
                    current_num_vowels += 1;
                }
            } else {

                if(max_num_vowels < current_num_vowels) max_num_vowels = current_num_vowels;

                if(ptr2 == s.size()) break;
                if(max_num_vowels == k) break;

                if( is_vowel(s[ptr1]) ) {
                    current_num_vowels--;
                }
                ptr1++;

                if( is_vowel(s[ptr2]) ) {
                    current_num_vowels += 1;
                }

            }

            ptr2++;
        }

        return max_num_vowels;
        
    }
};
