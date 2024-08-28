class Solution {
public:

    int push_number(vector<char>& chars, int num) {

        int num_chars_pushed = 0;
        while(num != 0) {

            int digit = num % 10;
            num = num / 10;

            chars.push_back('0' + digit);
            num_chars_pushed++;
        }

        return num_chars_pushed;
    }

    int compress(vector<char>& chars) {

        char prev_char = chars[chars.size() - 1];
        int num_current_char = 0;

        int i = 1;
        while(1) {

            int end_index = chars.size() - i;

            if(prev_char == chars[end_index]) {

                prev_char = chars[end_index];

                auto it = chars.begin() + end_index;
                num_current_char++;
                chars.erase(it);
            } else {


                if(num_current_char > 1) {
                    int num_chars_pushed = push_number(chars, num_current_char);
                    i += num_chars_pushed;
                }
                chars.push_back(prev_char);
                i++;

                prev_char = chars[end_index];
                auto it = chars.begin() + end_index;
                num_current_char = 1;
                chars.erase(it);
            }


            if(end_index == 0) {
                if(num_current_char > 1) push_number(chars, num_current_char);
                chars.push_back(prev_char);
                break;
            }
        }

        reverse(chars.begin(), chars.end());
        return chars.size();
        
    }
};
