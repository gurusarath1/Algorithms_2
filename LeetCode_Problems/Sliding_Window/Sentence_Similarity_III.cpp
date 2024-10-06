class Solution {
public:

    string get_next_word(string &sentence, int *loc) {
        string word = "";

        for(int i=*loc; i<sentence.size(); i++) {
            if(sentence[i] == ' ') {
                *loc += 1;
                break;
            } else {
                word += sentence[i];
            }

            *loc += 1;
        }

        return word;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string> words1;
        vector<string> words2;

        int loc = 0;
        int prev_loc = -1;
        while(prev_loc < loc) {
            prev_loc = loc;
            string word = get_next_word(sentence1, &loc);
            if(word != "") words1.push_back(word);
        }

        loc = 0;
        prev_loc = -1;
        while(prev_loc < loc) {
            prev_loc = loc;
            string word = get_next_word(sentence2, &loc);
            if(word != "") words2.push_back(word);
        }

        if(words1.size() > words2.size()) {
            return sand_wich(words2, words1);
        } else {
            return sand_wich(words1, words2);
        }

        return false;   
    }


    bool sand_wich(vector<string> &small_list, vector<string> &big_list) {

        int first_half_idx = 0;

        for(int i=0; i<big_list.size() && first_half_idx < small_list.size(); i++) {
            if(big_list[i] == small_list[first_half_idx]) {
                first_half_idx += 1;
            } else {Sentence Similarity III
                break;
            }
        }

        if(first_half_idx == small_list.size()) return true;
        int first_half_len = first_half_idx;

        int second_half_index = small_list.size() - 1;
        int second_half_len = 0;
        for(int j=big_list.size()-1; j>=0 && second_half_index >= 0; j--) {
            if(big_list[j] == small_list[second_half_index]) {
                second_half_index -= 1;
                second_half_len++;
            } else {
                break;
            }

            if((second_half_len + first_half_len) == small_list.size()) return true;
        }

        return false;
    }

};
