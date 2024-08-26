class Solution {
public:
    bool is_vowel(char c) {

        switch(c) {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                return true;
            default:
                return false;
        }

        return false;
    }

    string reverseVowels(string s) {

        int ptr1 = 0;
        int ptr2 = s.size() - 1;

        while(ptr1 < ptr2) {
            while( ptr1 < s.size() && !is_vowel(s[ptr1]) ) {
                ptr1++;
            }
            while( ptr2 >= 0 && !is_vowel(s[ptr2]) ) {
                ptr2--;
            }

            if(ptr1 >= ptr2) break;

            char c = s[ptr1];
            s[ptr1] = s[ptr2];
            s[ptr2] = c;

            ptr1++;
            ptr2--;
        }

        return s;
        
    }
};
